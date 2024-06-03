

#include "public/tmtc_dyn_mem.h"
#include "public/edroombp.h"
/**
 * \brief Maximum length of the memory block.
 */
#define TMTC_MAX_LENGTH       (TMTC_MAX_SIZE_IN_BYTES)

/**
 * \brief Maximum number of elements that can be allocated.
 */
#define TMTC_POOL_MAX_NOE    20

/**
 * \brief A memory pool for managing blocks of 256 unsigned 8-bit integers.
 *
 * This structure keeps track of the available free blocks and provides an
 * array of pre-allocated blocks for usage.
 */
struct tmtc_pool {

    uint8_t free_blocks[TMTC_POOL_MAX_NOE];

    uint8_t blocks[TMTC_POOL_MAX_NOE][TMTC_MAX_LENGTH];

};

/**
 * \brief The one and only instance of the pool.
 */
static struct tmtc_pool the_tmtc_pool;

static Pr_Mutex tmtc_pool_mutex_id;

void init_tmtc_pool() {


    for(uint8_t i = 0; i < TMTC_POOL_MAX_NOE; i++) {
        the_tmtc_pool.free_blocks[i] = 1;
    }

//    return status;

}


uint8_t * tmtc_pool_alloc() {

    uint8_t * ret = NULL;


    tmtc_pool_mutex_id.Wait();

    //find next free index
    for (uint32_t i = 0; i < TMTC_POOL_MAX_NOE; i = i + 1) {

        if (the_tmtc_pool.free_blocks[i] == 1) {
            ret = the_tmtc_pool.blocks[i];
            the_tmtc_pool.free_blocks[i] = 0;
            break;
        }

    }

    tmtc_pool_mutex_id.Signal();



    return ret;

}


void tmtc_pool_free(uint8_t * p_block) {

    uint32_t index, alignment;

    // Obtain the index of the block within the array
    index = (p_block - the_tmtc_pool.blocks[0]) / TMTC_MAX_LENGTH;
    alignment = (p_block - the_tmtc_pool.blocks[0]) % TMTC_MAX_LENGTH;

    if (index < TMTC_POOL_MAX_NOE && alignment == 0) {

    	tmtc_pool_mutex_id.Wait();
        the_tmtc_pool.free_blocks[index] = 1;
        tmtc_pool_mutex_id.Signal();
    }

}

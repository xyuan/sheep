#pragma once

#include <cassert>


/* COMPILE-TIME OPTIONS:
 * By default these options are all disabled, and this is reasonable.
 * Only enable them if you know what you are doing. */


/* OPTION: Deduplicate edges while loading the graph.
 * Enabling this option prevents multigraphs.
 * However, this option does not work with distributed loading. */
//#define DDUP_GRAPH


/* OPTION: Read and write vertex sequences in a binary format.
 * This is marginally more performant, but it makes it more difficult
 * to work with sequences generated by external programs. */
//#define USE_BIN_SEQUENCE


/* OPTION: Use a simpler union find without union-by-rank.
 * This saves a marginal amount of memory,
 * but has a non-marginal performance cost. */
//#define USE_SIMPLE_UF


/* OPTION: Save preorder weight for each vertex in the tree.
 * These weights are needed by some (non-default) partitioning models.
 * However, they consume sizeof(esize_t) bytes of memory per vertex.
 * This is a significant performance hit. */
//#define USE_PRE_WEIGHT


#define USE_LLAMA
//#define USE_SNAP

#ifdef USE_LLAMA
class LLAMAGraph;
typedef LLAMAGraph GraphWrapper;
typedef uint32_t vid_t;
typedef uint32_t esize_t;
#endif
#ifdef USE_SNAP
class SNAPGraph;
typedef SNAPGraph GraphWrapper;
typedef int vid_t;
typedef size_t esize_t;
#endif
#define INVALID_VID ((vid_t)-1)


#define KILO (1024)
#define MEGA (1024 * KILO)
#define GIGA (1024 * MEGA)


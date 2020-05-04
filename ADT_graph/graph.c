#include <stdlib.h>
#include <string.h>

#include "graph"
#include "linked-list.h"
#include "set.h"

void graph_inti(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
  graph->ecount = 0;
  graph->vcount = 0;
  graph->destroy = destroy;
  graph->match = match;
  list_init(&graph->adjlists, NULL);
  return;
}

void graph_destroy(Graph *graph)
{
  AdjList *adjlist;
  while (list_size(&graph->adjlists) > 0)
    {
      if (list_rem_next(&graph->adjlists, NULL, (void **)&adjlist) == 0)
	{
	  set_destroy(&adjlist->adjacent);
	  if (graph->destroy != NULL)
	    graph->destroy(adjlist->vertex);

	  free(adjlist);
	}
    }

  list_destroy(&graph->adjlists);
  memset(graph, 0, sizeof(Graph));
  return;
}

int graph_ins_vertex(Graph *graph, const void *data)
{
  ListElmt *element;
  AdjList *adjlist;
  int retval;

  for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
  {
    if (graph->match(data, ((AdjList *)list_data(element))->vertex))
      return 1;
  }

  if ((adjlist = (AdjList *)malloc(sizeof(AdjList))) == NULL)
    return -1;

  adjlist->vertex = (void *)data;
  set_init(&adjlist->adjacent, graph->match, NULL);

  if ((retval = list_ins_next(&graph->adjlists, list_tail(&graph->adjlists), adjlist)) != 0)
    return retval;

  graph->vcount++;

  return 0;
}







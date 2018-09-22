#include "../include/Graph.h"

Graph::Graph(Graph::Type numOfVertices_, Graph::Type numOfEdges_, const Graph::PairList &edges_):
  _numOfVertices(numOfVertices_),
  _numOfEdges(numOfEdges_)
{
  _adjacencyList.resize(_numOfVertices);

  for (const auto& pair : edges_)
  {
    addEdge(pair.first, pair.second);
  }
}

void Graph::addEdge(Type from_, Type to_)
{
  _adjacencyList[from_].push_back(to_);
}

const Graph::List &Graph::getAdjacents(Type from_) const
{
  return _adjacencyList[from_];
}
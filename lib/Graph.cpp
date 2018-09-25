#include "../include/Graph.h"
#include "../include/Exception.h"

#include <algorithm>
#include <iostream>

Graph::Graph(size_t numOfVertices_, const Graph::PairList &edges_):
  _numOfVertices(numOfVertices_)
{
  _adjacencyList.resize(_numOfVertices);

  for (const auto& pair : edges_)
  {
    addEdge(pair.first, pair.second);
  }
}

void Graph::addEdge(Type from_, Type to_)
{
  ASSERT((from_ >= 0) && (from_ < _numOfVertices) && (to_ >= 0) && (to_ < _numOfVertices),
    "Invalid indices: " + std::to_string(from_) + " -> " + std::to_string(to_));

  _adjacencyList[from_].push_back(to_);
  _adjacencyList[to_].push_back(from_);
  ++_numOfEdges;
}

const Graph::List &Graph::getAdjacentVertices(Type from_) const
{
  ASSERT((from_ >= 0) && (from_ < _numOfVertices), "Invalid index: " + std::to_string(from_));
  return _adjacencyList[from_];
}

auto Graph::hasEdge(Graph::Type from_, Graph::Type to_) const -> bool
{
  if (from_ >= _numOfVertices)
  {
    return false;
  }
  const auto& vec = _adjacencyList[from_];
  return std::find(std::cbegin(vec), std::cend(vec), to_) != std::cend(vec);
}
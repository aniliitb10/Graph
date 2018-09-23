#pragma once

#include <vector>

class Graph
{
public:
  using Type = int;
  using List = std::vector<Type>;
  using PairList = std::vector<std::pair<Type, Type>>;
  using AdjacencyList = std::vector<List>;

  explicit Graph(size_t numOfVertices_, const PairList& edges_);

  auto getNumOfVertices()       const { return _numOfVertices; }
  auto getNumOfEdges()          const { return _numOfEdges; }
  auto getAdjacentVertices(Type from_) const -> const List&;
  auto hasEdge(Type from_, Type to_) const -> bool;

  auto addEdge(Type from_, Type to_)  -> void;

private:
  const size_t  _numOfVertices;
  size_t        _numOfEdges = 0;
  AdjacencyList _adjacencyList;
};
#pragma once

#include <vector>

class Graph
{
public:
  using Type = unsigned long;
  using List = std::vector<Type>;
  using PairList = std::vector<std::pair<Type, Type>>;
  using AdjacencyList = std::vector<List>;

  explicit Graph(Type numOfVertices_, Type numOfEdges_, const PairList& edges_);

  auto getNumOfVertices()       const { return _numOfVertices; }
  auto getNumOfEdges()          const { return _numOfEdges; }
  auto getAdjacents(Type from_) const -> const List&;

  auto addEdge(Type from_, Type to_)  -> void;

private:
  Type          _numOfVertices;
  Type          _numOfEdges;
  AdjacencyList _adjacencyList;
};
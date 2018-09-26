#pragma once

#include "../include/Graph.h"
#include <vector>

class BFS
{
public:
  using IntVec = std::vector<int>;

  explicit BFS(const Graph& graph_, int source_);
  bool connected(int destination_) const;
  IntVec path(int destination_) const;

private:

  struct ConnInfo
  {
    bool _marked;
    int  _reachedFrom;
  };
  using ConnInfoList = std::vector<ConnInfo>;

  void bfs(const Graph& graph_, int source_);

  ConnInfoList _connInfoList;
  const int    _source;
};
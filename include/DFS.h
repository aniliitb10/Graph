#pragma once

#include "Graph.h"
#include <vector>
#include <list>

class DFS
{
public:
  using IntList = std::list<int>;

  explicit DFS(const Graph& graph_, int source_);
  bool connected(int destination_) const;
  IntList path(int destination_) const;

private:

  struct ConnInfo
  {
    bool _marked;
    int  _reachedFrom;
  };
  using ConnInfoList = std::vector<ConnInfo>;

  void dfs(const Graph& graph_, int vertex_);

  ConnInfoList _connInfoList;
  const int    _source;
};
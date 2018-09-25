#include "../include/DFS.h"

DFS::DFS(const Graph& graph_, int source_):
_source(source_)
{
  _connInfoList.resize(graph_.getNumOfVertices());
  dfs(graph_, source_);
}

bool DFS::connected(int destination_) const
{
  return _connInfoList[destination_]._marked;
}

DFS::IntVec DFS::path(int destination_) const
{
  std::list<int> path;

  if (!connected(destination_))
  {
    return DFS::IntVec{};
  }

  path.emplace_front(destination_);

  auto reachedFrom = _connInfoList[destination_]._reachedFrom;
  while (reachedFrom != _source)
  {
    path.emplace_front(reachedFrom);
    reachedFrom = _connInfoList[reachedFrom]._reachedFrom;
  }
  path.emplace_front(_source);

  return DFS::IntVec{std::begin(path), std::end(path)};
}

void DFS::dfs(const Graph& graph_, int vertex_)
{
  _connInfoList[vertex_]._marked = true;

  for (int adjacentVertex : graph_.getAdjacentVertices(vertex_))
  {
    if (_connInfoList[adjacentVertex]._marked)
    {
      return; // it has already been visited
    }

    _connInfoList[adjacentVertex]._reachedFrom = vertex_;
    dfs(graph_, adjacentVertex);
  }
}

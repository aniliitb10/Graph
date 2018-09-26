#include "../include/BFS.h"
#include "../include/Exception.h"
#include <queue>
#include <list>

BFS::BFS(const Graph &graph_, int source_):
_source(source_)
{
  ASSERT(source_ >= 0 && source_ < graph_.getNumOfVertices(), "Invalid source vertex: " + std::to_string(source_));
  _connInfoList.resize(graph_.getNumOfVertices());
  bfs(graph_, _source);
}

bool BFS::connected(int destination_) const
{
  if ((destination_ < 0) || (destination_ >= _connInfoList.size()))
  {
    return false;
  }
  return _connInfoList[destination_]._marked;
}

BFS::IntVec BFS::path(int destination_) const
{
  if ((destination_ < 0) || (destination_ >= _connInfoList.size()) || !connected(destination_))
  {
    return BFS::IntVec{};
  }

  std::list<int> path;
  path.emplace_front(destination_);

  auto reachedFrom = _connInfoList[destination_]._reachedFrom;
  while(reachedFrom != _source)
  {
    path.emplace_front(reachedFrom);
    reachedFrom = _connInfoList[reachedFrom]._reachedFrom;
  }
  path.emplace_front(_source);
  return BFS::IntVec {std::begin(path), std::end(path)};
}

void BFS::bfs(const Graph &graph_, int source_)
{
  std::queue<int> queue;
  queue.emplace(source_);

  while(!queue.empty())
  {
    auto vertex = queue.front();
    queue.pop();

    for (auto neighbour : graph_.getAdjacentVertices(vertex))
    {
      if (_connInfoList[neighbour]._marked)
      {
        continue; // it has already been visited
      }

      _connInfoList[neighbour]._reachedFrom = vertex;
      _connInfoList[neighbour]._marked = true;
      queue.emplace(neighbour);
    }
  }
}

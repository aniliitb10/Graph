#include "../include/BFS.h"
#include <gtest/gtest.h>

struct BFSTest : public ::testing::Test
{
  const Graph::PairList _edges = {{0,5}, {4,3}, {0,1}, {6,4}, {5,4}, {0,2}, {0,6}, {5,3}, {4,7}};
  const Graph _graph{8, _edges};
  const BFS _bfs{_graph, 0};

  static const BFS::IntVec& printPath(const BFS::IntVec& path_)
  {
    for (auto vertex : path_)
    {
      std::cout << vertex << " -> ";
    }
    std::cout << "\n";
    return path_;
  }
};

TEST_F(BFSTest, ConnectivityTest)
{
  EXPECT_TRUE(_bfs.connected(1));
  EXPECT_TRUE(_bfs.connected(2));
  EXPECT_TRUE(_bfs.connected(3));
  EXPECT_TRUE(_bfs.connected(4));
  EXPECT_TRUE(_bfs.connected(5));
  EXPECT_TRUE(_bfs.connected(6));
  EXPECT_TRUE(_bfs.connected(7));

  EXPECT_FALSE(_bfs.connected(8));
  EXPECT_FALSE(_bfs.connected(9));
}

TEST_F(BFSTest, PathTest)
{
  EXPECT_EQ(printPath(_bfs.path(1)).size(), 2);
  EXPECT_EQ(printPath(_bfs.path(2)).size(), 2);
  EXPECT_EQ(printPath(_bfs.path(3)).size(), 3);
  EXPECT_EQ(printPath(_bfs.path(4)).size(), 3);
  EXPECT_EQ(printPath(_bfs.path(5)).size(), 2);
  EXPECT_EQ(printPath(_bfs.path(6)).size(), 2);
  EXPECT_EQ(printPath(_bfs.path(7)).size(), 4);
}

#include "../include/DFS.h"
#include "../include/Graph.h"

#include <gtest/gtest.h>

struct DFSTest : public ::testing::Test
{
  const Graph::PairList _edges = {{0,5}, {4,3}, {0,1}, {6,4}, {5,4}, {0,2}, {0,6}, {5,3},
                                  {7,8}, {7,9}, {8,9}};
  const Graph _graph{10, _edges};
  const DFS _dfs{_graph, 0};

  static void validatePath(const DFS::IntVec& path_, const Graph::PairList& edges_, int source_, int destination_)
  {
    EXPECT_TRUE(std::size(path_) > 1);
    EXPECT_EQ(source_, *path_.begin());
    EXPECT_EQ(destination_, *(std::prev(path_.end(), 1)));
    auto pathItr = std::begin(path_);
    auto from = *pathItr;
    std::advance(pathItr, 1);
    while (pathItr != std::end(path_))
    {
      auto toItr = std::find(std::begin(edges_), std::end(edges_), std::make_pair(from, *pathItr));
      EXPECT_TRUE(toItr != std::end(edges_));
      from  = *pathItr;
      std::advance(pathItr, 1);
    }
  }
};

TEST_F(DFSTest, ConnectivityTest)
{
  EXPECT_TRUE(_dfs.connected(1));
  EXPECT_TRUE(_dfs.connected(2));
  EXPECT_TRUE(_dfs.connected(3));
  EXPECT_TRUE(_dfs.connected(4));
  EXPECT_TRUE(_dfs.connected(5));
  EXPECT_TRUE(_dfs.connected(6));

  EXPECT_FALSE(_dfs.connected(7));
  EXPECT_FALSE(_dfs.connected(8));
  EXPECT_FALSE(_dfs.connected(9));
}

TEST_F(DFSTest, PathTest)
{
  validatePath(_dfs.path(1), _edges, 0, 1);
  validatePath(_dfs.path(2), _edges, 0, 2);
  validatePath(_dfs.path(3), _edges, 0, 3);
  validatePath(_dfs.path(4), _edges, 0, 4);
  validatePath(_dfs.path(5), _edges, 0, 5);
  validatePath(_dfs.path(6), _edges, 0, 6);
}
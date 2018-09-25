#include "../include/Graph.h"
#include "../include/Exception.h"
#include "../include/DFS.h"

#include <gtest/gtest.h>

struct GraphTest : public ::testing::Test
{
  const Graph::PairList _edges = {{0,5}, {4,3}, {0,1}, {6,4}, {5,4}, {0,2}, {0,6}, {5,3}};
  const Graph _graph{7, _edges};
};

TEST_F(GraphTest, VerticesTest)
{
  EXPECT_EQ(_graph.getNumOfVertices(), 7);
}

TEST_F(GraphTest, EdgesTest)
{
  //Edge tests related to vertex 0
  EXPECT_EQ(_graph.getNumOfEdges(), 8);
  EXPECT_TRUE(_graph.hasEdge(0, 5));
  EXPECT_FALSE(_graph.hasEdge(0, -1));
}

TEST_F(GraphTest, AdjacentsTest)
{
  const auto& adjacentVertices = _graph.getAdjacentVertices(0);
  Graph::List expectedAdjacentVertices = {5,1,2,6};
  EXPECT_EQ(adjacentVertices, expectedAdjacentVertices);
}

TEST_F(GraphTest, IndicesTest)
{
  Graph::PairList edges = {{0,5}, {4,3}, {0,1}, {6,4}, {5,4}, {0,2}, {0,6}, {5,3}};
  Graph graph{7, edges};

  EXPECT_THROW(graph.addEdge(-1, 0), Exception);
  EXPECT_THROW(graph.addEdge(0, -1), Exception);
  EXPECT_THROW(graph.addEdge(-1, -1), Exception);
  EXPECT_NO_THROW(graph.addEdge(0, 0));
}
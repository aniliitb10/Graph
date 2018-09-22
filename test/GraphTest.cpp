#include "../include/Graph.h"

#include <gtest/gtest.h>

struct GraphTest : public ::testing::Test
{
  const Graph::PairList edges = {{0,5}, {4,3}, {0,1}, {6,4}, {5,4}, {0,2}, {0,6}, {5,3}};
  const Graph graph{8, 7, edges};
};

TEST_F(GraphTest, VerticesTest)
{
  EXPECT_EQ(graph.getNumOfVertices(), 8);
}

TEST_F(GraphTest, EdgesTest)
{
  EXPECT_EQ(graph.getNumOfEdges(), 7);
}

TEST_F(GraphTest, AdjacentsTest)
{
  const auto& adjacents = graph.getAdjacents(0);
  EXPECT_EQ(adjacents.size(), 4);
}
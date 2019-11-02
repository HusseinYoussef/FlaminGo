#pragma once

#include <cfloat>
#include <vector>

#define TreeNode int

enum result
{
    WIN = 1,
    LOSE = 0
};

// Monte Carlo Tree Search class
class MCTS
{
private:
    // LoopTimer timer;
    int iterations;


public:

    float UCB1_C;           // Value of C in UCB1 function: sqrt(2), 2, 1.5
    int max_iterations;     // max # of iteration to run MCTS
    int max_millis;         // max time to run MCTS
    int simulation_depth;   // max depth to run simulation

    MCTS();
    // TODO
    // const LoopTimer & get_timer() const;
    int get_iterations() const;
    TreeNode* get_best_child(TreeNode*, float) const;
    TreeNode* get_most_visited_child(TreeNode*) const;
    TreeNode* Select(TreeNode*) const;
    TreeNode* Expand(TreeNode*) const;
    result Simulate(State state) const;
    void Propagate(TreeNode*, float) const;
    Action run(const State&, int, vector(State)*);

    ~MCTS();
};

MCTS::MCTS()
{
}

MCTS::~MCTS()
{
}


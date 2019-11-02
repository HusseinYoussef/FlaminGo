#include "MCTS.h"
#include "math.h"

//TODO: Tune the values
MCTS :: MCTS()
{
    iterations = 0;
    UCB1_C = sqrt(2);
    max_iterations = 0;
    max_millis = 0;
    simulation_depth = 0;
}

int MCTS :: get_iterations() const
{
    return iterations;
}

// get best child for given node based on UCB score
TreeNode* MCTS :: get_best_child(TreeNode* node, float ucb_c) const
{
    // The node should be fully expanded (generated all its child) to choose among them
    if(!node->is_fully_expanded())
    {
        return NULL;
    }

    float best_ucb_score = -1;
    TreeNode* best_node = NULL;

    int num_children = node->get_num_children();
    for(int i = 0; i < num_children; ++i)
    {
        TreeNode* child = node->get_child(i);
        // (wk / nk) + C * sqrt(ln(n par) / nk)
        float ucb_exploitation = (float)child->get_value() / child->get_num_visits();
        float ucb_exploration = sqrt(log(node->get_num_visits()) / child->get_num_visits());
        float ucb_score = ucb_exploitation + UCB1_C * ucb_exploration;

        if(ucb_score > best_ucb_score)
        {
            best_ucb_score = ucb_score;
            best_node = child;
        }
    }

    return best_node;
}

TreeNode* MCTS :: get_most_visited_child(TreeNode* node) const
{
    int most_visits = -1;
    TreeNode* best_node = NULL;

    int num_childs = node->get_num_children();
    for(int i = 0; i<num_childs; ++i)
    {
        TreeNode* child = node->get_child(i);
        if(child->get_num_visits() > most_visits)
        {
            most_visits = child->get_num_visits();
            best_node = child;
        }
    }

    return best_node;
}

TreeNode* MCTS :: Select(TreeNode* root_node) const
{

    while(!node->is_terminal() && node->is_fully_expanded())
    {
        node = get_best_child(node, UCB1_C);
    }
    return node;
}

Action MCTS :: run(const State& current_state, int seed = 1, vector<State>* explored_states = NULL)
{
    timer.init();

    TreeNode root_node(current_state);

    TreeNode* best_node = NULL;
    iterations = 0;

    while(true)
    {
        timer.loop_start();


        // SELECT
        TreeNode* node = &root_node;
        
    }
}

MCTS::~MCTS()
{

}
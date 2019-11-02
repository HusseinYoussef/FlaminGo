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

// Descend, return node with best score
TreeNode* MCTS :: Select(TreeNode* node) const
{
    while(!node->is_terminal() && node->is_fully_expanded())
    {
        node = get_best_child(node, UCB1_C);
    }
    return node;
}

// Expand, Expand by adding single child (if not terminal or not fully expanded)
TreeNode* MCTS :: Expand(TreeNode* node) const
{
    if(!node->is_fully_expanded() && !node->is_terminal())
    {
        node = node->expand();
    }
    return node;
}

//Simulate, Apply random actions till the game ends(win or lose)
result MCTS :: Simulate(State state) const
{
    if(!node->is_terminal())
    {
        Action action;
        for(int d = 0; d < simulation_depth; ++d)
        {
            if(state.is_terminal())
            {
                break;
            }

            if(state.get_random_action(action))
            {
                state.apply_action(action);
            }
            else
            {
                break;
            }
        }
    }

    float reward = state.evalute();
    
    if(reward)
    {
        return WIN;
    }
    return LOSE;
}

//Back Propagation, Update the path of hte node
void MCTS :: Propagate(TreeNode* node, float reward) const
{
    while(node)
    {
        node->update(reward);
        node = node->get_parent();
    }
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

        // 1. SELECT
        TreeNode* node = Select(&root_node);

        // 2. Expand
        node = Expand(node);

        State state(node->get_state());
        
        // 3. Simulate
        float reward = Simulate(state);

        if(explored_states)
        {
            explored_states->push_back(state);
        }

        // 4. BACK PROPAGATION
        Propagate(node, reward);

        best_node = get_most_visited_child(&root_node);

        timer.loop_end();
        if(max_millis > 0 && timer.check_duration(max_millis)) break;

        // exit loop if current iterations exceeds max_iterations
        if(max_iterations > 0 && iterations > max_iterations) break;
        iterations++;
    }

    // Return the action to the best node
    if(best_node) 
    {
        return best_node->get_action();
    }

    return Action();
}

MCTS::~MCTS()
{

}
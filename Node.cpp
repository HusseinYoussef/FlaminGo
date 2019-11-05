#pragma once
#include "definitions.h"
#include "Node.h"
#include "assert.h"
Node::Node(State& state, Node* parent = NULL):
                state(state),
                action(),
                parent(parent),
				player(state.get_player()),
                visits_count(0),
                wins(0),
                depth(parent ? parent->depth + 1 : 0)
{}

//All nodes share the same game engine.
GoEngine Node::engine = GoEngine();

Node* Node::expand()
{
    // First check if this Node is fully expanded or not.
    if(is_fully_expanded()) return NULL;

    // Check if this is the first expansion.
    if(children.empty()){

        // Get the list of actions that this Node can do.
        actions = engine.getValidMoves(&state,(parent == NULL? NULL:& (parent->state) ), current_color);
        //state.get_actions(actions);
        // Shuffle these actions. To randomly pick a child.
        std::random_shuffle(actions.begin(),actions.end());  // This part will change when ML comes.
    }

    // If there is no actions, then this Node is a terminal Node, and u shouldn't be here!
    assert("ERROR! the Node have no actions to perform and classified as normal Node not terminal node" && !actions.empty());

    Node* child = add_child(actions.back()); // NOTE: for every call of function "expand",this function will
    actions.pop_back();
    return child;
}

void Node::update(result reward)
{
    wins+=(reward == WIN); // MIND BELOW.
    visits_count++;
}

Node* Node::add_child(const Action& new_action)
{
    // Create a new Node with the same state.
    Node* child = new Node(state,this);
    // Fill its action.
    child->action = new_action;
    // Change its state to the new state( old state + new action )
    child->state.apply_action(new_action);
    // Now add it to the children list.
    children.push_back(child);
    return child;
}

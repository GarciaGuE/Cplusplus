#include <cassert>
#include "trie.hpp"
#include <iostream>
#ifdef assert
//We undefined this macro to not shadow our implementation of assert.
#undef assert
#endif

/**
 * @brief Check an assertion.
 * In Debug mode, if the assertion is not met, a segfault is generated.
 * @param assertion
 */
inline void assert(bool assertion){
	#ifndef NDEBUG
		(void)((assertion) || (__assert ("Assert violation!", __FILE__, __LINE__),0));
	#endif
}


TrieNode::TrieNode(){};

TrieNode::Ref TrieNode::create(){return std::make_shared<TrieNode>();}

bool
TrieNode::has(char k) const{
    bool ret_v = false;
    for(auto &it:children_){
        if(it.first==k){
        	if(it.second!=nullptr)
        		ret_v=true;
        }
    }
    return ret_v;
}

TrieNode::Ref
TrieNode::child(char k) const{
    assert(has(k));
    TrieNode::Ref ret_v;
    for(auto &it:children_){
        if(it.first==k)
        	return it.second;
    }
    return ret_v;
}

std::string const&
TrieNode::value() const{return value_;}

const std::map<char, TrieNode::Ref> &TrieNode::children() const{return children_;}

void
TrieNode::set_value(std::string const& new_v){value_ = new_v;}

void
TrieNode::insert(char k, Ref node){children_[k]=node;}

Trie::Trie(){}

Trie::Ref Trie::create(){return std::make_shared<Trie>();}

TrieNode::Ref Trie::root() const{return root_;}

bool
Trie::has(std::string const& k) const{
    bool found = false;
    TrieNode::Ref node;
	node=find_node(k);
	found=(node!=nullptr) && (node->value()==k);
    return found;
}

std::vector<std::string>
Trie::keys(std::string const& pref) const{
    std::vector<std::string> keys;
    TrieNode::Ref node;
    node=find_node(pref);
    if(node!=nullptr)
	    preorder_traversal(node, keys);
    return keys;
}


void
Trie::insert(std::string const& k){
	if(root_==nullptr)
		root_=std::make_shared<TrieNode>();
	TrieNode::Ref node=root_;
	for(unsigned i=0; i<k.size(); i++){
		if(node->has(k[i]))
			node=node->child(k[i]);
		else{
			TrieNode::Ref newnode=std::make_shared<TrieNode>();
			node->insert(k[i], newnode);
			node=newnode;
		}
	}
	node->set_value(k);
    assert(has(k));
}

TrieNode::Ref
Trie::find_node(std::string const& pref) const{
    TrieNode::Ref node;
        unsigned i=0;
	node=root_;
	while(i<pref.size() && node!=nullptr){
		if(node->has(pref[i])){
			node=node->child(pref[i]);
			i++;
		}
		else
			node=nullptr;
	}
    return node;
}

void
Trie::preorder_traversal(TrieNode::Ref const& node,
                         std::vector<std::string> & keys) const{
	if(node->value()!="")
		keys.push_back(node->value());
	for(auto &it:node->children())
		preorder_traversal(it.second, keys);
}

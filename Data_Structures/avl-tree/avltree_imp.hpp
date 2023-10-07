#pragma once

#include "avltree.hpp"

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

/****
 * AVLTNode class implementation.
 ****/


template <class T>
AVLTNode<T>::AVLTNode (T const& it, AVLTNode<T>::Ref parent,
                       AVLTNode<T>::Ref left, AVLTNode<T>::Ref right):
    item_(it), parent_(parent), left_(left), right_(right), height_(0){

    assert(check_height_invariant());
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::create(T const& it,
                                              AVLTNode<T>::Ref parent,
                                              AVLTNode<T>::Ref left,
                                              AVLTNode<T>::Ref right){

    return std::make_shared< AVLTNode<T> > (it, parent, left, right);
}

template <class T>
const T& AVLTNode<T>::item() const{
    return item_;
}

template <class T>
int AVLTNode<T>::height() const{
    return height_;
}

template <class T>
int AVLTNode<T>::balance_factor() const{
    int bf = 0;
    if(has_left() && has_right())
      bf=(right()->height())-(left()->height());
    else if(has_left() && !has_right())
      bf=(-1)-(left()->height());
    else if(!has_left() && has_right())
      bf=(right()->height())-(-1);
    return bf;
}

template <class T>
bool AVLTNode<T>::has_parent() const{
    if(parent_!=nullptr)
      return true;
    else
      return false;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::parent() const{
    return parent_;
}

template <class T>
bool AVLTNode<T>::has_left() const{
    if(left_!=nullptr)
      return true;
    else
      return false;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::left() const{
    return left_;
}

template <class T>
bool AVLTNode<T>::has_right() const{
    if(right_!=nullptr)
      return true;
    else
      return false;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::right() const{
    return right_;
}

template <class T>
bool AVLTNode<T>::check_height_invariant () const{
    bool ret_val = false;
    int max=-1;
    if(has_left() && has_right()){
      if(left_->height()>=right_->height())
        max=left_->height();
      else
        max=right_->height();
    }
    else if(has_left() && !has_right())
      max=left_->height();
    else if(!has_left() && has_right())
      max=right_->height();
    
    if(height()==(1+max))
      ret_val=true;
    return ret_val;
}

template <class T>
void AVLTNode<T>::set_item(const T& new_it){
    item_=new_it;
    assert(item()==new_it);
}

template <class T>
void AVLTNode<T>::set_parent(AVLTNode<T>::Ref const& new_parent){
    parent_=new_parent;
    compute_height();
    assert(parent()==new_parent);
}

template <class T>
void AVLTNode<T>::remove_parent(){
    parent_=nullptr;
    compute_height();
    assert(!has_parent());
}

template <class T>
void AVLTNode<T>::set_left(AVLTNode<T>::Ref const& new_child){
    left_=new_child;
    compute_height();
    assert(check_height_invariant());
    assert(left()==new_child);
}

template <class T>
void AVLTNode<T>::remove_left(){
    left_=nullptr;
    compute_height();
    assert(check_height_invariant());
    assert(!has_left());
}

template <class T>
void AVLTNode<T>::set_right(AVLTNode<T>::Ref const& new_child){
    right_=new_child;
    compute_height();
    assert(check_height_invariant());
    assert(right()==new_child);
}

template <class T>
void AVLTNode<T>::remove_right(){
    right_=nullptr;
    compute_height();
    assert(check_height_invariant());
    assert(!has_right());
}

template <class T>
void AVLTNode<T>::compute_height(){
    int aux=-1;
    int aux2=-1;
    for(int i=1;i<=2;i++){
      if(i==1 && has_left())
        aux=left_->height();
      if(i==2 && has_right())
        aux2=right_->height();
    }
    if(aux>=aux2 )
      height_=aux+1;
    else
      height_=aux2+1;
    assert(check_height_invariant());
}

/***
 * AVLTree class implementation.
 ***/

template <class T>
AVLTree<T>::AVLTree (){
    root_=nullptr;
    current_=root_;
    prev_=nullptr;
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
}

template <class T>
AVLTree<T>::AVLTree (T const& item){
    root_=std::make_shared<AVLTNode<T>>(item, nullptr, nullptr, nullptr);
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create (){
  return std::make_shared< AVLTree<T> >();
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create (T const& item){
  return std::make_shared<AVLTree<T>> (item);
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create(std::istream& in) noexcept(false){
    auto tree=AVLTree<T>::create();
    std::string token;
    in>>token;
    if(!in)
      throw std::runtime_error("Wrong input format");
    
    T data;
    if(token=="["){
      in>>token;
      std::istringstream str(token);
      str>>data;
      tree->create_root(data);
      auto treeL=AVLTree<T>::create();
      treeL=AVLTree<T>::create(in);
      tree->set_left(treeL);
      auto treeR=AVLTree<T>::create();
      treeR=AVLTree<T>::create(in);
      tree->set_right(treeR);
      in>>token;
      if(token!="]"){
        throw std::runtime_error("Wrong input format");
      }
    }
    else{
        if(token!="[]")
          throw std::runtime_error("Wrong input format");
    }
    if(!tree->is_a_binary_search_tree())
        throw std::runtime_error("It is not a binary search tree");
    if(!tree->is_a_balanced_tree())
        throw std::runtime_error("It is not an avl bstree");
    return tree;
}

#ifdef __ONLY_BSTREE__
/**
 * @brief Create a BSTree by inserting the median of an ordered sequence.
 * @param data is an ordered sequence of keys.
 * @param begin,
 * @param end specify a [begin, end) indexing interval of data to use.
 * @pre data values are in order.
 * @pre 0 <= begin <= end <=data.size()
 */
template<class T>
void create_inserting_median(std::vector<T> const& data,
                             size_t begin,
                             size_t end,
                             typename AVLTree<T>::Ref& tree){
    assert(begin<=end);
    assert(end<=data.size());

    //Hint: use a recursive design by inserting the median of input
    // (begin, end] interval
    //and recursively, apply to each sub-interval [begin, median),
    //[median+1, end).
    size_t sz=end-begin;
    if(sz>0){
      tree->insert(data[begin+(sz/2)]);
      create_inserting_median(data,begin,begin+(sz/2),tree);
      create_inserting_median(data,begin+(sz/2)+1,end,tree);
    }
}

template<class T>
typename AVLTree<T>::Ref AVLTree<T>::create(std::vector<T> & data){
    assert(data.size()>0);
    auto tree=AVLTree<T>::create();
    std::sort(data.begin(), data.end());
    create_inserting_median(data, 0, data.size(), tree);
    return tree;
}
#endif //#ifdef __ONLY_BSTREE__

template <class T>
bool AVLTree<T>::is_empty () const{
    if(root_==nullptr)
      return true;
    else
      return false;
}

template <class T>
T const& AVLTree<T>::item() const{
    return root_->item();
}

template <class T>
std::ostream& AVLTree<T>::fold(std::ostream& out) const{
    if(is_empty()==true)
      out<<"[]";
    else{
      out<<"[ ";
      out<<item();
      out<<" ";
      left()->fold(out);
      out<<" ";
      right()->fold(out);
      out<<" ]";
    }
    return out;
}

template <class T>
bool AVLTree<T>::current_exists() const{
    if(current_!=nullptr)
      return true;
    else
      return false;
}

template <class T>
T const& AVLTree<T>::current() const{
    assert(current_exists());
    return current_->item();
}

template <class T>
int AVLTree<T>::current_level() const{
    assert(current_exists());
    int level=0;
    std::shared_ptr<AVLTNode<T>> aux=root_;
    while(aux!=current_){
      level=level+1;
      if(current_->item()<aux->item())
        aux=aux->left();
      else
        aux=aux->right();
    }
    return level;
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::left() const{
    assert(!is_empty());
    AVLTree<T>::Ref lsb;
    lsb=lsb->create();
    lsb->root_=root_->left();
    return lsb;
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::right() const{
    assert(!is_empty());
    AVLTree<T>::Ref rsb;
    rsb=rsb->create();
    rsb->root_=root_->right();
    return rsb;
}

template <class T>
int AVLTree<T>::size() const{
    int s=0;
    if(!is_empty())
      s=1+left()->size()+right()->size();
    return s;
}

template <class T>
int AVLTree<T>::height() const{
    int h=-1;
    if(!is_empty())
      h=root_->height();
    return h;
}

template <class T>
int AVLTree<T>::balance_factor() const{
#ifdef __ONLY_BSTREE__
    return 0;
#else
    int bf=0;
    if(root_!=nullptr)
      bf=root_->balance_factor();
    return bf;
#endif
}

template <class T>
bool AVLTree<T>::has(const T& k) const{
#ifndef NDEBUG
  bool old_current_exists=current_exists();
  T old_current;
  if(old_current_exists)
    old_current=current();
#endif

  bool found=true;

  found=false;
  if(!is_empty()){
    if(k<root_->item())
      found=left()->has(k);
    else if(k > root_->item())
      found=right()->has(k);
    else
      found=true;
  }
#ifndef NDEBUG
  assert (!old_current_exists || old_current==current());
#endif
  return found;
}

template <class T>
bool AVLTree<T>::is_a_binary_search_tree() const{
    bool is_bst = true;
    if(!is_empty()){
      if(!left()->is_empty()){
        if(item()<left()->item() || (left()->item()<0))
          is_bst=false;
      }
      if(!right()->is_empty()){
        if(item()>right()->item())
          is_bst=false;
      }
      if(is_bst==true)
        is_bst=is_bst && left()->is_a_binary_search_tree() && right()->is_a_binary_search_tree();
    }
    return is_bst;
}

template <class T>
bool AVLTree<T>::is_a_balanced_tree() const{
#ifdef __ONLY_BSTREE__
    return true;
#else
    bool is_balanced=true;
    if(!is_empty()){
      if(!left()->is_empty()){
        if(balance_factor()<=-2 || balance_factor()>=2)
          is_balanced=false;
      }
      if(!right()->is_empty()){
        if(balance_factor()<=-2 || balance_factor()>=2)
          is_balanced=false;
      }
      if(is_balanced==true)
        is_balanced=is_balanced && left()->is_a_balanced_tree() && right()->is_a_balanced_tree();
    }
    return is_balanced;
#endif
}

template <class T>
void AVLTree<T>::create_root(T const& item){
    assert(is_empty());
    root_=std::make_shared<AVLTNode<T>>(item, nullptr, nullptr, nullptr);
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(!is_empty());
    assert(this->item()==item);
}

template <class T>
bool AVLTree<T>::search(T const& k){
    bool found=false;
    current_=root_;
    prev_=nullptr;
    while((current_ !=nullptr) && (!found)){
      if(current_->item()==k)
        found=true;
      else{
        prev_=current_;
        if(current_->item()>k)
          current_=current_->left();
        else
          current_=current_->right();
      }
    }
    assert(!found || current()==k);
    assert(found || !current_exists());
    return found;
}

template <class T>
void AVLTree<T>::insert(T const& k){
    if(!search(k)){
      if(is_empty()){
        current_=std::make_shared<AVLTNode<T>> (k, nullptr, nullptr, nullptr);
        root_=current_;
      }
      else{
        current_=std::make_shared<AVLTNode<T>> (k, nullptr, nullptr, nullptr);
        if(prev_->item()>k){
          current_->set_parent(prev_);
          prev_->set_left(current_);
        }
        else{
          current_->set_parent(prev_);
          prev_->set_right(current_);
        }
      }
#ifdef __ONLY_BSTREE__
        assert(is_a_binary_search_tree());
#else
        assert(is_a_binary_search_tree());
        make_balanced();
        assert(is_a_balanced_tree());
#endif
    }

    //Check postconditions.
    assert(current_exists());
    assert(current()==k);
}

template <class T>
void AVLTree<T>::remove (){
    //Check preconditions.
    assert(current_exists());

    bool replace_with_subtree=true;
    typename AVLTNode<T>::Ref subtree;

    // Check which of cases 0,1,2,3 we have.
    if(!current_->has_left() && !current_->has_right())
      subtree=nullptr;
    else if(!current_->has_right())
      subtree=current_->left();
    else if(!current_->has_left())
      subtree=current_->right();
    else
      replace_with_subtree=false;
    if(replace_with_subtree==true){
        //Manage cases 0,1,2
        if(prev_==nullptr){
          root_=subtree;
          current_=nullptr;
        }
        else if(prev_->right()==current_){
          prev_->set_right(subtree);
          current_=nullptr;
        }
        else{
          prev_->set_left(subtree);
          current_=nullptr;
        }
#ifdef __ONLY_BSTREE__
        assert(is_a_binary_search_tree());
        assert(! current_exists());
#else
        assert(is_a_binary_search_tree());
        make_balanced();
        assert(is_a_balanced_tree());
        assert(! current_exists());
#endif
    }
    else{
      //Manage case 3.
      std::shared_ptr< AVLTNode<T>> tmp=current_;
      find_inorder_sucessor();
      tmp->set_item(current_->item());
      remove();
      current_=nullptr;
    }
}

template <class T>
AVLTree<T>::AVLTree (typename AVLTNode<T>::Ref root_node){
  root_=root_node;
}

template <class T>
typename AVLTree<T>::Ref  AVLTree<T>::create (typename AVLTNode<T>::Ref root){
  AVLTree<T>::Ref ret_v (new AVLTree<T>(root));
  return ret_v;
}

template <class T>
typename AVLTNode<T>::Ref const&  AVLTree<T>::root() const{
    return root_;
}

template <class T>
void AVLTree<T>::set_left(typename AVLTree<T>::Ref& subtree){
    assert(!is_empty());
    //Remenber to set parent's link of the subtree root to this.
    root_->set_left(subtree->root_);
    assert(subtree->is_empty() || left()->item()==subtree->item());
    assert(!subtree->is_empty() || left()->is_empty());
}

template <class T>
void AVLTree<T>::set_right(typename AVLTree<T>::Ref& subtree){
    assert(!is_empty());
    //Remenber to set parent's link of the subtree root to this.
    root_->set_right(subtree->root_);
    assert(subtree->is_empty()|| right()->item()==subtree->item());
    assert(!subtree->is_empty()|| right()->is_empty());
}

template <class T>
void AVLTree<T>::find_inorder_sucessor(){
    assert(current_exists());
#ifndef NDEBUG
    T old_curr=current();
#endif
    if(current_->has_right()){
      prev_=current_;
      current_=current_->right();
      while(current_->has_left()){
        prev_=current_;
        current_=current_->left();
      }
    }
    assert(current_exists());
#ifndef NDEBUG
    assert(current()>old_curr);
#endif
}

template <class T>
void AVLTree<T>::rotate_left(typename AVLTNode<T>::Ref node){
    //Remenber when set a node A as child of a node B, also is needed set
    // node B as parent of node A.
    std::shared_ptr<AVLTNode<T>> lc;
    lc=node->left();
    if(!node->has_parent())
      root_=lc;
    else if(node->parent()->right()==node)
      node->parent()->set_right(lc);
    else
      node->parent()->set_left(lc);
    lc->set_parent(node->parent());
    if(lc->has_right()){
      node->set_left(lc->right());
      lc->right()->set_parent(node);
    }
    else
      node->remove_left();
    lc->set_right(node);
    node->set_parent(lc);
    node->compute_height();
    lc->compute_height();
}

template <class T>
void AVLTree<T>::rotate_right(typename AVLTNode<T>::Ref node){
    //Remenber when set a node A as child of a node B, also is needed set
    // node B as parent of node A.
    std::shared_ptr< AVLTNode<T> > rc;
    rc=node->right();
    if(!node->has_parent())
      root_=rc;
    else if(node->parent()->right()==node)
      node->parent()->set_right(rc);
    else
      node->parent()->set_left(rc);
    rc->set_parent(node->parent());
    if(rc->has_left()){
      node->set_right(rc->left());
      rc->left()->set_parent(node);
    }
    else
      node->remove_right();
    rc->set_left(node);
    node->set_parent(rc);
    node->compute_height();
    rc->compute_height();
}

template <class T>
void AVLTree<T>::make_balanced(){
#ifdef __ONLY_BSTREE__
    return;
#else
    //From current position, go up until root's node is achieved.
    //In each step, check if the current subtree is balanced and balance it
    // if not.
    int bfP;
    int bfC;
    std::shared_ptr< AVLTNode<T> > child;
    std::shared_ptr< AVLTNode<T> > parent_=prev_;
    while(parent_!=nullptr){
      parent_->compute_height();
      bfP=parent_->balance_factor();
      if(bfP<-1){
        child=parent_->left();
        bfC=child->balance_factor();
        if(bfC<=0)
          rotate_left(parent_);
        else{
          rotate_right(child);
          rotate_left(parent_);
        }
      }
      else if(bfP>1){
          child=parent_->right();
          bfC=child->balance_factor();
          if(bfC>=0)
            rotate_right(parent_);
          else{
            rotate_left(child);
            rotate_right(parent_);
          }
      }
      parent_=parent_->parent();
    }
    if(current_exists()){
        // Remember that due to the rotations, the state of attributes curr and prev
        // may be inconsistent, so we need to force that "previous of current" is the
        // parent of "current" when current_exists().
        prev_=current_->parent();
    }


#endif //__ONLY_BSTREE__
}

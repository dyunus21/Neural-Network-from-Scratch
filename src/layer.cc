#include "layer.hpp"

#include <cstring>

Layer::Layer(int size) {
  preActivationNodes = new Node[size];
  postActivationNodes = new Node[size];
  shape.push_back(size);
}

Layer::~Layer() {
  delete[] preActivationNodes;
  delete[] postActivationNodes;
}

void Layer::clear() {
  std::memset(preActivationNodes, 0, getTotalSize() * sizeof(Node));
  std::memset(postActivationNodes, 0, getTotalSize() * sizeof(Node));
}

void Layer::update(Optimizer& optimizer) {}

Node* Layer::getPreActivationNodes() { return preActivationNodes; }

Node* Layer::getPostActivationNodes() { return postActivationNodes; }

std::vector<int> Layer::getShape() const { return shape; }

int Layer::getTotalSize() const {
  int tot = 1;
  for (int dim : shape) tot *= dim;
  return tot;
}
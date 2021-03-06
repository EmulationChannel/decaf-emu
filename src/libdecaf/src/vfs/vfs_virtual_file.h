#pragma once
#include "vfs_virtual_node.h"

#include <cstdint>
#include <vector>

namespace vfs
{

struct VirtualFile : public VirtualNode
{
   VirtualFile() :
      VirtualNode(VirtualNode::File)
   {
   }
   ~VirtualFile() override = default;

   std::vector<uint8_t> data;
};

} // namespace vfs

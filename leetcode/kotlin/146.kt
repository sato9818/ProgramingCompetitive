// Amazon
class LRUCache(capacity: Int) {
  private val capacity = capacity
  private data class Node(
      val key: Int,
      var value: Int,
      var prev: Node? = null,
      var next: Node? = null
  )

  private val nodes = mutableMapOf<Int, Node>()

  private var left = Node(0,0)
  private var right = Node(0,0)

  private var size = 0

  init {
      left.next = right
      right.prev = left
  }

  private fun remove(node: Node) {
      val prev = node.prev
      val next = node.next

      prev?.next = next
      next?.prev = prev
      nodes.remove(node.key)
      size--
  }

  private fun insert(node: Node) {
      if(node.key in nodes) {
          // Update Cache
          // Remove from Doubly LinkedList and hashmap
          remove(nodes[node.key]!!)
          // Insert new node with same key
          insert(node)
      } else {
          // Insert to hashmap
          nodes[node.key] = node
          // Insert the node at most right
          val head = right.prev
          head?.next = node
          right.prev = node
          node.prev = head
          node.next = right
          size++
      }
  }

  fun get(key: Int): Int {
      if(key in nodes) {
          val node = nodes[key]!!
          insert(node)
          return node.value
      } else{
          return -1
      }
      
  }

  fun put(key: Int, value: Int) {
      insert(Node(key, value))
      if(size > capacity) {
          remove(left.next!!)
      }
  }

}

/**
* Your LRUCache object will be instantiated and called as such:
* var obj = LRUCache(capacity)
* var param_1 = obj.get(key)
* obj.put(key,value)
*/
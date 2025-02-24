class Solution {
    private val moveX = listOf(0,1,0,-1)
    private val moveY = listOf(1,0,-1,0)
    fun isRobotBounded(instructions: String): Boolean {
        var moveIndex = 0
        var x = 0
        var y = 0

        instructions.forEach { instruction ->
            when(instruction) {
                'G' -> {
                    x += moveX[moveIndex]
                    y += moveY[moveIndex]
                }
                'L' -> {
                    moveIndex--
                    if(moveIndex < 0) {
                        moveIndex = 3
                    }
                }
                'R' -> {
                    moveIndex++
                    if(moveIndex > 3) {
                        moveIndex = 0
                    }
                }
                else -> {}
            }
            
        }

        return x == 0 && y == 0 || moveIndex != 0
    }
}

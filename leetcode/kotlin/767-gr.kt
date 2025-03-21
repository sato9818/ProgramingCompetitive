class Solution {
    fun reorganizeString(s: String): String {
        val count = MutableList(26) {0}
        var maxCount = 0
        var maxChar = 'a'
        for(ch in s) {
            val idx = ch - 'a'
            count[idx]++
            if(maxCount < count[idx]) {
                maxCount = count[idx]
                maxChar = 'a' + idx
            }
        }

        val res = MutableList<Char>(s.length){' '}

        var index = 0
        while(count[maxChar - 'a'] > 0) {
            if(index > s.length-1) {
                println(index)
                return ""
            }
            res[index] = maxChar
            count[maxChar - 'a']--
            index += 2
        }
        
        for(i in 0..25) {
            while(count[i] > 0) {
                if(index > s.length-1) {
                    index = 1
                }
                res[index] = ('a' + i)
                count[i]--
                index += 2
            }
        }
        
        var ans = ""
        for(ch in res) {
            ans += ch
        }
        return ans
    }
}

// Time: O(n) n: the length of s
// Space: O(n + m) m: the number of unique character
package Neetcode.Stack;

import java.util.Stack;

public class largestrecthist {

}

class Solution {
  public int largestRectangleArea(int[] heights) {
    if (heights == null || heights.length == 0) {
      return 0;
    }

    Stack<Integer> st = new Stack<>();
    st.push(-1);
    int max = 0;

    for (int i = 0; i < heights.length; i++) {
      while (st.size() != 1 && heights[i] < heights[st.peek()]) {
        max = Math.max(max, heights[st.pop()] * ((i - 1) - st.peek()));
      }
      st.push(i);
    }

    while (st.size() != 1) {
      max = Math.max(max, heights[st.pop()] * ((heights.length - 1) - st.peek()));
    }

    return max;
  }
}
class Solution {
    public int buyChoco(int[] prices, int money) {
        Arrays.sort(prices);
        int n = prices.length;
      int min=prices[0]+prices[1];
      if(min<=money){
        return money-min;
      }
      return money;
    }
}

// LANGUAGE: Javas //Getter Setter
// ENV: Java 8 
// AUTHOR: Noopur Agarwal
// GITHUB: https://github.com/noopurAg

//Using two pointers method O(n) time and O(1) space

//Container is filler with water which cant be tilted or slanted
class ContainerWithMostWater {
    public int maxArea(int[] height) {
        int maxarea=0;
        int start = 0; int end = height.length-1;
        while(start<end){
            maxarea = Math.max(maxarea, 
                               Math.min(height[start],height[end])*(end-start));
            if(height[start]< height[end])start++;
            else end--;
        }
        return maxarea;
    }
    
    public static void main(String args[]){
    
    ContainerWithMostWater container = new ContainerWithMostWater();
    int[] height= [1,8,6,2,5,4,8,3,7];
    int maxArea = container.maxArea(height);
    System.out.println("Area maximum container by the water ", maxArea);
    }
}

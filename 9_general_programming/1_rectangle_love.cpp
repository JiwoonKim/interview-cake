/**
 *  Calculate the overlap between two rectangles
 *  (the rectangles are always straight and never diagonal)
 * 
 *  Time Complexity: O(1)
 *  Space Complexity: O(1)
 * 
 *  * solution
 * 
 *    - break the problem into SUBPROBLEMS
 *      : intersection = horizontal overlap && vertical overlap
 *       
 *    - use HELPER FUNCTIONS to find overlap in each X, Y dimension
 *      : draw out possible cases of overlapping & not overlapping
 *      
 *      => SAME as merging ranges problem (ex. 1-1. merge meeting times)
 * 
 *  ** What I learned:
 * 
 *     * RECT class = START POINT + WIDTH + HEIGHT
 *       - instead of defining all 4 coordinates
 *       - defined using 1 coord on bottom left
 *         + width + height
 *       => less complicated and saves more space
 * 
 *     * define custom data structure for RANGE
 *       - MAKE IT EASY TO CONVERT BACK AND FORTH to RECT objects
 *         : use START POINT + LENGTH
 *           -> method for end point for efficiency
 * 
 *       => define custom data structure considering ADAPTABILITY between classes
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  define RECT class
*/
class Rectangle {
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    // constructors
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height):
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    // retrieve coordinates or dimensions
    int getLeftX() const {
        return  leftX_;
    }
    int getBottomY() const {
        return  bottomY_;
    }
    int getWidth() const {
        return  width_;
    }
    int getHeight() const {
        return  height_;
    }

    // check rectangle equivalance (if coordinates and dimensions match)
    bool operator==(const Rectangle& other) const {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const {
        return !(*this == other);
    }
};

/**
 *  define RANGE class to find X-overlap & Y-overlap
 *  (custom data structure class)
*/
class Range {
private:
    int startPoint;
    int length;

public:
    // constructor
    Range(int startPoint, int length) {
        this->startPoint = startPoint;
        this->length = length;
    }

    // retrieve start point, length, end point
    int getStartPoint() const {
        return startPoint;
    }
    int getLength() const {
        return length;
    }
    int getEndPoint() const {
        return startPoint + length;
    }

    // compare ranges (used for sorting)
    bool operator<(const Range& other) const {
        if (startPoint < other.startPoint) {
            return getEndPoint() < other.getEndPoint();
        }
        return startPoint < other.startPoint;
    }
};

/**
 *  helper function to find overlapping range
*/
Range findOverlappingRange(const Range& range1, const Range& range2) {
    
    /** sort the two ranges
     *  (so that ranges[0] is always to the left of range[1])
    */ 
    vector<Range> ranges = { range1, range2 };
    sort(ranges.begin(), ranges.end());
    
    // if the two ranges overlap,
    if (range1.getEndPoint() > range2.getStartPoint()) {
        int overlappingLength = min(range2.getLength(), range1.getEndPoint() - range2.getStartPoint());
        return Range(range2.getStartPoint(), overlappingLength);
    }
    // else, the two touch or there is no overlap at all
    return Range(0, 0);
}

/**
 * calculate the overlap between the two rectangles
*/ 
Rectangle findRectangularOverlap(const Rectangle& rect1, const Rectangle& rect2) { 

    // get overlapping X-range
    Range rect1_x_range = Range(rect1.getLeftX(), rect1.getWidth());
    Range rect2_x_range = Range(rect2.getLeftX(), rect2.getWidth());
    Range x_overlap = findOverlappingRange(rect1_x_range, rect2_x_range);
    
    // get overlapping Y-range
    Range rect1_y_range = Range(rect1.getBottomY(), rect1.getHeight());
    Range rect2_y_range = Range(rect2.getBottomY(), rect2.getHeight());
    Range y_overlap = findOverlappingRange(rect1_y_range, rect2_y_range);
    
    // construct Rectangle object with x and y intersection ranges
    Rectangle rectOverlap = Rectangle();
    if (x_overlap.getStartPoint() > 0 && y_overlap.getStartPoint() > 0) {
        rectOverlap = Rectangle(x_overlap.getStartPoint(), y_overlap.getStartPoint(), x_overlap.getLength(), y_overlap.getLength());
    }
    return rectOverlap;
}

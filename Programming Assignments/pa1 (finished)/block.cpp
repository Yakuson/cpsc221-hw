#include "block.h"
#include <cmath>
#include <iostream>

using namespace std;

/* Returns the width, in pixels
 * of the current block
 */
int Block::width() const
{
    // Your code here!
    if(data.size() == 0) {
        return 0;
    }

    return data[0].size();
}

/* Returns the width, in pixels
 * of the current block
 */
int Block::height() const
{
    // Your code here!
    if (data.empty()) {
        return 0;
    }
    return data.size();
}

/* Given an image whose size is large enough, place
 * the current block in the image so that its upper left corner
 * is at position column, row. Existing pixels in the image
 * will be replaced by those of the block.
 */
void Block::render(PNG &im, int column, int row) const
{
    // Your code here!
    for(int i = 0; i < height(); i++) {
        for(int j = 0; j < width(); j++) {
            HSLAPixel* p = im.getPixel(column + j, row + i);
            *p = data[i][j];
        }
    }
    
}

/* create a block of pixels whose color values are the same as the
 * rectangle in the image described by the upper left corner (column, row)
 * whose size is width x height.
 */
void Block::build(PNG &im, int column, int row, int width, int height)
{
    // Your code here!
    //HSLAPixel* temp = new HSLAPixel;
    HSLAPixel* p;

    data.resize(height);
    for (int y = 0; y < height; y++) {

        vector<HSLAPixel> temp;
        temp.resize(width);

        for (int x = 0; x < width; x++) {
            HSLAPixel* p = im.getPixel(x + column, y + row);
            temp[x] = *p;
        }
        data[y] = temp;
    }

}

/* Flip the current block across its horizontal midline.
 * This function changes the existing block.
 */
void Block::flipVert()
{
    // Your code here!
    reverse(data.begin(), data.end());
}

/* Flip the current block across its vertical midline.
 * This function changes the existing block.
 */
void Block::flipHoriz()
{
    // Your code here!
    for (int y = 0; y < height(); y++) {
        reverse(data[y].begin(), data[y].end());
    }
}

/* Rotate the current block 90 degrees counterclockwise.
 * This function changes the existing block.
 */
void Block::rotateRight()
{
    // Your code here!
    vector<vector<HSLAPixel>> temp;
	temp.resize(height());

	for (int y = 0; y < height(); y++) {
		temp[y] = vector<HSLAPixel>{};
		temp[y].resize(width());
	}

	for (int i = 0; i < height(); i++) {
		for (int j = 0; j < width(); j++) {
			temp[i][j] = data[fabs(j - (width() - 1))][i];
		}
	}

	data = temp;
}

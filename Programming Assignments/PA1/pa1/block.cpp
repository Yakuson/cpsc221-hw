#include "block.h"
#include <cmath>
#include <iostream>

/* Returns the width, in pixels
 * of the current block
 */
int Block::width() const
{
    // Your code here!
}

/* Returns the width, in pixels
 * of the current block
 */
int Block::height() const
{
    // Your code here!
}

/* Given an image whose size is large enough, place
 * the current block in the image so that its upper left corner
 * is at position column, row. Existing pixels in the image
 * will be replaced by those of the block.
 */
void Block::render(PNG &im, int column, int row) const
{
    // Your code here!
}

/* create a block of pixels whose color values are the same as the
 * rectangle in the image described by the upper left corner (column, row)
 * whose size is width x height.
 */
void Block::build(PNG &im, int column, int row, int width, int height)
{

    // Your code here!

}

/* Flip the current block across its horizontal midline.
 * This function changes the existing block.
 */
void Block::flipVert()
{
    // Your code here!
}

/* Flip the current block across its vertical midline.
 * This function changes the existing block.
 */
void Block::flipHoriz()
{
    // Your code here!
}

/* Rotate the current block 90 degrees counterclockwise.
 * This function changes the existing block.
 */
void Block::rotateRight()
{
    // Your code here!
}
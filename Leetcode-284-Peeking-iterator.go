/*   Below is the interface for Iterator, which is already defined for you.
 *
 *   type Iterator struct {
 *
 *   }
 *
 *   func (this *Iterator) hasNext() bool {
 *		// Returns true if the iteration has more elements.
 *   }
 *
 *   func (this *Iterator) next() int {
 *		// Returns the next element in the iteration.
 *   }
 */

type PeekingIterator struct {
	iter *Iterator
	tmp  int
}

func Constructor(iter *Iterator) *PeekingIterator {
	return &PeekingIterator{
		iter: iter,
		tmp:  -1,
	}
}

func (this *PeekingIterator) hasNext() bool {
	return this.iter.hasNext() || this.tmp != -1
}

func (this *PeekingIterator) next() int {
	if this.tmp != -1 {
		rv := this.tmp
		this.tmp = -1
		return rv
	} else {
		return this.iter.next()
	}
}

func (this *PeekingIterator) peek() int {
	if this.tmp == -1 {
		this.tmp = this.iter.next()
	}
	return this.tmp
}
def flatten(nested_iterable):

    """ Accepts an iterable of iterables and returns a flattened generator.
    Example:
        > sequence = [[[1, 2], [3, [4]]], [[5, 6], [7, 8, [9, 10]]]]
        > list(flatten(sequence))
        [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    """

    for item in nested_iterable:
        if hasattr(item, '__iter__') and not isinstance(item, str):
            for i in flatten(item):
                yield i
        else:
            yield item
            

class Node:
    def __init__(self, value,
                 left = None,
                 right = None):
        self.left = left
        self.right = right
        self.value = value


class Vector:
    def __init__(self):
        self._items = []

    def __iter__(self):
        for item in self._items:
            yield item

    def __bool__(self):
        return len(self._items) > 0

    def push(self, item):
        self._items.append(item)

    def pop(self):
        return self._items.pop()

    def top(self):
        return self._items[-1]


def create_btree():
    return Node(1,
                Node(2,
                     Node(4),
                     Node(5,
                          Node(7),
                          Node(8))),
                Node(3,
                     Node(6)))


def post_order(root):
    vector = Vector()
    vector.push([root, False, False])

    output = 'pos_order: '

    while vector:
        top = vector.top()
        node = top[0]

        if not top[1]:
            if node.left:
                vector.push([node.left, False, False])
            top[1] = True
            continue

        if not top[2]:
            if node.right:
                vector.push([node.right, False, False])
            top[2] = True
            continue

        output += '{},'.format(node.value)
        vector.pop()

    print(output.rstrip(','))


def pre_order(root):
    vector = Vector()
    vector.push(root)

    output = 'pre_order: '

    while vector:
        node = vector.pop()

        output += '{},'.format(node.value)

        if node.right:
            vector.push(node.right)

        if node.left:
            vector.push(node.left)

    print(output.rstrip(','))


def mid_order(root):
    vector = Vector()
    vector.push([root, False])

    output = 'mid_order: '

    while vector:
        top = vector.top()

        node = top[0]

        if not top[1]:
            if node.left:
                vector.push([node.left, False])
            top[1] = True
            continue
        else:
            output += '{},'.format(node.value)
            vector.pop()

        if node.right:
            vector.push([node.right, False])

    print(output.rstrip(','))


def main():
    root = create_btree()
    post_order(root)
    pre_order(root)
    mid_order(root)


if __name__ == '__main__':
    main()

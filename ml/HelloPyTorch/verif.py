

from __future__ import print_function
import torch


if __name__ == "__main__":
    x = torch.zeros(5, 3, dtype=torch.long)
    print(x)

    x = torch.tensor([5.5, 3])
    print(x)

    x = x.new_ones(5, 3, dtype=torch.double)
    print(x)

    x = torch.randn_like(x, dtype=torch.float)
    print(x)

    print(x.size())
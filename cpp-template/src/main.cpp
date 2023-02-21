/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <vector>
#include <string>

int main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);

    // Range-based for loop with Initialization
	for(std::vector<int> vec {1, 2, 3, 4}; auto const &v : vec)
	{
		printk("item: %s\n", std::to_string(v).c_str());
	}
	
    // 3-way comparisons
	int a = 91, b = 110;
    auto ans1 = a <=> b;
  
    if (ans1 < 0) {
        printk("a < b");
    }
    else if (ans1 == 0) {
        printk("a == b");
    }
    else if (ans1 > 0) {
        printk("a > b");
    }
}

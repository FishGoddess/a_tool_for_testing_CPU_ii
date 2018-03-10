# a_tool_for_testing_CPU_ii
## after writing an easy tool to test CPU, I complete it into a "look-like-high-level" version... so this guy was borned!

但是，我觉得单线程的完成时间实在太慢。。。而且有些机器比较老的，CPU 性能相对较弱，完成整个测试需要花费相当多的时间.

所以，我在 2017 年的 2 月份又重新写了一个测试器。。。就是这个东西。。。

它和上一个版本最大的不同就是测试原理不同。上一个记录完成任务的时间，这个是相同时间完成的任务数量。

正因为如此，它可以在很短时间内（默认 20 秒）交出测试结果。但在一些机子上准确度不如上一个版本高。

比如散热较差、CPU 会降频的笔记本，由于他的测试时间较短，所以很可能会导致在这类机子上测试结果偏高。



Because that, its time is too long in some old CPUs, I have to write another software... 

That is it!

It will take 20 second to finish some missions, and the result is how many missions it finished!

Oh, it may not really sure when it is testing a bad heat radiating notebook. Believe me, it works in most situation!

So, eh... it takes less time than the "old" version...

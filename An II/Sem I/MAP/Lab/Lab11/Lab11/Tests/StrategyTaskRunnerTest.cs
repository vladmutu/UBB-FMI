using Lab11.Enums;
using Lab11.Runners;

namespace Lab11.Tests;

public class StrategyTaskRunnerTest
{
    public static void strategyTaskRunnerTest(Strategy containerStrategy, MessageTask?[] messageTasks) {
        TaskRunner taskRunner = new StrategyTaskRunner(containerStrategy);
        taskRunner.addTask(messageTasks[0]);
        taskRunner.addTask(messageTasks[1]);
        taskRunner.addTask(messageTasks[2]);
        taskRunner.executeAll();
    }
}
using Lab11.Enums;
using Lab11.Runners;

namespace Lab11.Tests;

public class PrinterTaskRunnerTest
{
    public static void printerTaskRunnerTest(Strategy containerStrategy, MessageTask?[] messageTasks) {
        StrategyTaskRunner strategyTaskRunner = new StrategyTaskRunner(containerStrategy);
        PrinterTaskRunner printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
        printerTaskRunner.addTask(messageTasks[0]);
        printerTaskRunner.addTask(messageTasks[1]);
        printerTaskRunner.addTask(messageTasks[2]);
        printerTaskRunner.executeAll();
    }
}
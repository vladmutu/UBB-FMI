package Tests;

import Model.MessageTask;
import Runners.PrinterTaskRunner;
import Runners.StrategyTaskRunner;
import Enums.Strategy;

public class PrinterTaskRunnerTest {

    public static void printerTaskRunnerTest(Strategy containerStrategy, MessageTask[] messageTasks) {
        StrategyTaskRunner strategyTaskRunner = new StrategyTaskRunner(containerStrategy);
        PrinterTaskRunner printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
        printerTaskRunner.addTask(messageTasks[0]);
        printerTaskRunner.addTask(messageTasks[1]);
        printerTaskRunner.addTask(messageTasks[2]);
        printerTaskRunner.executeAll();
    }
}
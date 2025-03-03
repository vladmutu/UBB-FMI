package Factory;

import Container.Container;
import Container.QueueContainer;
import Container.StackContainer;
import Enums.Strategy;

public class TaskContainerFactory implements Factory {
    //private constructor
    //public static Factory.TaskContainerFactory getInstance()
    private TaskContainerFactory() {

    }

    private static final TaskContainerFactory instance = new TaskContainerFactory();

    public static TaskContainerFactory getInstance(){
        return instance;
    }
    @Override
    public Container createContainer(Strategy strategy) {
        switch (strategy) {
            case Strategy.FIFO -> {
                return new QueueContainer();
            }
            case Strategy.LIFO -> {
                return new StackContainer();
            }
        }
        return null;
    }
}

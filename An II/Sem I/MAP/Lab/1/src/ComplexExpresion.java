import java.util.Arrays;

public abstract class ComplexExpresion {
    private Operation operation;
    NumarComplex[] args;

    public ComplexExpresion(Operation operation, NumarComplex[] args) {
        this.operation = operation;
        this.args = args;
    }

    @Override
    public String toString() {
        return "ComplexExpresion{" +
                "operation=" + operation +
                ", args=" + Arrays.toString(args) +
                '}';
    }

    public abstract NumarComplex executeOneOperation(NumarComplex operand1, NumarComplex operand2);

    public NumarComplex execute() {
        NumarComplex result = args[0];
        for(int i = 1; i < args.length; i++) {
            result = executeOneOperation(result, args[i]);
        }
        return result;
    }
}

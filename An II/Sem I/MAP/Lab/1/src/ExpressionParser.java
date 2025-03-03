import java.util.Objects;

public class ExpressionParser {
    private final String[] args;

    public ExpressionParser(String[] args) {
        this.args = args;
    }

    public ComplexExpresion parse() {
        String op = args[1];
        for(int i = 1; i < args.length; i+=2)
        {
            if(!Objects.equals(args[i], op))
                throw new RuntimeException();
        }
        NumarComplex[] argss = new NumarComplex[(args.length + 1) / 2];
        for (int i = 0; i < args.length; i++) { // pe pozitii pare sunt nr complexe, impare operanzii
            if (i % 2 == 0) { // nr complex
                int negativ = 0;
                String[] el = args[i].split("[+]", 2);
                if (el.length != 2) {
                    el = args[i].split("-", 2);
                    negativ = 1;
                }
                String[] IM;
                double re;
                try {
                    re = Double.parseDouble(el[0]);
                    IM = el[1].split("[*]", 2);
                }catch(NumberFormatException e){
                    throw new RuntimeException(e);
                }
                double im;
                if(IM.length == 1)
                    im = 1;
                else
                    try{
                        im = Double.parseDouble((IM[0]));
                    }catch(NumberFormatException e){
                        throw new RuntimeException(e);
                    }
                if (negativ == 1) {
                    im = -im;
                }
                NumarComplex nr = new NumarComplex(re, im);
                argss[i / 2] = nr;
            } else {
                op = args[i];
                if (!Objects.equals(op, "+") && !Objects.equals(op, "-") && !Objects.equals(op, "*") && !Objects.equals(op, "/")) {
                    throw new RuntimeException();
                }
            }
        }

        return switch (op) {
            case "+" -> ExpressionFactory.getInstance().createExpression(Operation.ADDITION, argss);
            case "-" -> ExpressionFactory.getInstance().createExpression(Operation.SUBSTRACTION, argss);
            case "*" -> ExpressionFactory.getInstance().createExpression(Operation.MULTIPLICATION, argss);
            case "/" -> ExpressionFactory.getInstance().createExpression(Operation.DIVISION, argss);
            default -> null;
        };
    }
}
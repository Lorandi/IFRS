package genericos;

//classe genérica com dois tipos de parâmetros
public class Par <P, S>{
    private P primeiro;
    private S segundo;
    public Par(){}
    public Par(P p, S s){
        primeiro = p; segundo = s;
    }
    public P getPrimeiro(){return primeiro;}
    public S getSegundo(){return segundo;}
    public void setPrimeiro(P p){primeiro= p;}
    public void setSegundo(S s){segundo = s;}
    public String toString(){ return primeiro + " " + segundo; }
}

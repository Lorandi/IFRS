package classes;

import enums.Situacao;
import jakarta.persistence.*;

import java.io.Serial;
import java.io.Serializable;
import java.time.LocalDate;
import java.util.Date;
import java.util.HashSet;
import java.util.Objects;
import java.util.Set;


@Entity
public class Projeto implements Serializable {

    @Serial
    private static final long serialVersionUID = 1L;

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "data_inicio", nullable = false)
    private Date dataInicio;

    @Column(name = "data_fim")
    private LocalDate dataFim;

    @ElementCollection(fetch = FetchType.LAZY)
    @CollectionTable(name="participantes")
    private Set<String> participantes = new HashSet<>();

    @Enumerated(EnumType.STRING)
    private Situacao situacao;


    public Projeto() {
    }

    public Projeto(Date dataInicio,  Situacao situacao) {
        this.dataInicio = dataInicio;
        this.situacao = situacao;
    }

    public Projeto(Date dataInicio, HashSet<String> participantes, Situacao situacao) {
        this.dataInicio = dataInicio;
        this.participantes = participantes;
        this.situacao = situacao;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Date getDataInicio() {
        return dataInicio;
    }

    public void setDataInicio(Date dataInicio) {
        this.dataInicio = dataInicio;
    }

    public LocalDate getDataFim() {
        return dataFim;
    }

    public void setDataFim(LocalDate dataFim) {
        this.dataFim = dataFim;
    }

    public Set<String> getParticipantes() {
        return participantes;
    }

    public void setParticipantes(HashSet<String> participantes) {
        this.participantes = participantes;
    }

    public Situacao getSituacao() {
        return situacao;
    }

    public void setSituacao(Situacao situacao) {
        this.situacao = situacao;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Projeto projeto = (Projeto) o;
        return Objects.equals(id, projeto.id) && Objects.equals(dataInicio, projeto.dataInicio) && Objects.equals(dataFim, projeto.dataFim) && Objects.equals(participantes, projeto.participantes) && situacao == projeto.situacao;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, dataInicio, dataFim, participantes, situacao);
    }

    @Override
    public String toString() {
        return "Projeto{" +
                "id=" + id +
                ", dataInicio=" + dataInicio +
                ", dataFim=" + dataFim +
                ", participantes=" + participantes +
                ", situacao=" + situacao +
                '}';
    }
}
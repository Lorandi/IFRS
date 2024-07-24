package datas;

import java.io.Serializable;
import java.time.LocalDate;

import jakarta.persistence.*;
import java.util.*;
import enums.*;

@Entity
public class Usuario3 implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id 
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long idUsuario;
    private String identificador;
    private String senha;
    
    @Enumerated(EnumType.STRING) 
    private Perfil perfil; 
   
//    @Temporal(TemporalType.DATE)
//    @Column(name = "data_cadastro", nullable = false)
//    private Date dataCadastro;
    
    @Column(name = "data_cad", nullable = false)
    private Date dataCadastro;

    @Column(name = "data_nascimento")
    private LocalDate dataNascimento;
  
    public Usuario3(){}

    public Usuario3(String identificador, String senha) {
        this(identificador, senha, null, null);
    }
 
    public Usuario3(String identificador, String senha, Perfil perfil, Date data) {
        this.identificador = identificador;
        this.senha = senha;
        this.perfil = perfil;
        this.dataCadastro = data;
    }

    public Usuario3(String identificador, String senha, Perfil perfil, Date data, LocalDate dataNascimento) {
        this.identificador = identificador;
        this.senha = senha;
        this.perfil = perfil;
        this.dataCadastro = data;
        this.dataNascimento = dataNascimento;
    }


    public Long getIdUsuario() {
        return idUsuario;
    }

    public void setIdUsuario(Long id) {
        this.idUsuario = id;
    }

    public String getIdentificador() {
        return identificador;
    }

    public void setIdentificador(String identificador) {
        this.identificador = identificador;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }
	

	public Perfil getPerfil() {
		return perfil;
	}

	public void setPerfil(Perfil perfil) {
		this.perfil = perfil;
	}


	public Date getDataCadastro() {
		return dataCadastro;
	}

	public void setDataCadastro(Date dataCadastro) {
		this.dataCadastro = dataCadastro;
	}

	@Override
    public int hashCode() {
        int hash = 0;
        hash += (idUsuario != null ? idUsuario.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Usuario3)) {
            return false;
        }
        Usuario3 other = (Usuario3) object;
        if ((this.idUsuario == null && other.idUsuario != null) || (this.idUsuario != null && !this.idUsuario.equals(other.idUsuario))) {
            return false;
        }
        return true;
    }

	@Override
	public String toString() {
		return "Usuario3 [idUsuario=" + idUsuario + ", identificador=" + identificador + ", senha=" + senha
				+ ", perfil=" + perfil + ", dataCadastro=" + dataCadastro + "]";
	}

	

   
}

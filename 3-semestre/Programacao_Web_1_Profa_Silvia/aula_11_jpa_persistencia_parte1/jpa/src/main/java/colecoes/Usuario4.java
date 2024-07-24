package colecoes;

import java.io.Serializable;
import java.time.LocalDate;

import javax.persistence.Entity;
import javax.persistence.*;
import java.util.*;
import enums.*;

@Entity
public class Usuario4 implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id 
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long idUsuario;
    private String identificador;
    private String senha;
    
    @Enumerated(EnumType.STRING) 
    private Perfil perfil; 

    @ElementCollection
    @CollectionTable(name="usuario_tem_emails")
    private Set<String> emails;

    @Temporal(TemporalType.DATE)
    @Column(name = "data_cadastro", nullable = false)
    private Date dataCadastro;
    
    /*@Column(name = "data_cad", nullable = false) 
    private LocalDate dataCadastro;*/

    
    public Usuario4(){}

    public Usuario4(String identificador, String senha, Set<String> emails) {
        this(identificador, senha, emails, null);
    }
 
    public Usuario4(String identificador, String senha, Set<String> emails, Perfil perfil) {
        this.identificador = identificador;
        this.senha = senha;
        this.emails = emails;
        this.perfil = perfil;
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

    public Set<String> getEmails() {
		return emails;
	}

	public void setEmails(Set<String> emails) {
		this.emails = emails;
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
        if (!(object instanceof Usuario4)) {
            return false;
        }
        Usuario4 other = (Usuario4) object;
        if ((this.idUsuario == null && other.idUsuario != null) || (this.idUsuario != null && !this.idUsuario.equals(other.idUsuario))) {
            return false;
        }
        return true;
    }

	@Override
	public String toString() {
		return "Usuario [idUsuario=" + idUsuario + ", identificador=" + identificador + ", senha=" + senha + ", perfil="
				+ perfil + ", emails=" + emails + ", dataCadastro=" + dataCadastro + "]";
	}

   
}

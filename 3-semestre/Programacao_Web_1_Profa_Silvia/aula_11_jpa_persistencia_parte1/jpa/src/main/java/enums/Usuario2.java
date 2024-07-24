package enums;

import java.io.Serializable;
import java.time.LocalDate;

import javax.persistence.Entity;
import javax.persistence.*;
import java.util.*;
import enums.*;

@Entity
public class Usuario2 implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id 
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long idUsuario;
    private String identificador;
    private String senha;
    
    @Enumerated(EnumType.STRING) 
    private Perfil perfil; 

  
    public Usuario2(){}

    public Usuario2(String identificador, String senha) {
        this(identificador, senha, null);
    }
 
    public Usuario2(String identificador, String senha, Perfil perfil) {
        this.identificador = identificador;
        this.senha = senha;
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
	

	public Perfil getPerfil() {
		return perfil;
	}

	public void setPerfil(Perfil perfil) {
		this.perfil = perfil;
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
        if (!(object instanceof Usuario2)) {
            return false;
        }
        Usuario2 other = (Usuario2) object;
        if ((this.idUsuario == null && other.idUsuario != null) || (this.idUsuario != null && !this.idUsuario.equals(other.idUsuario))) {
            return false;
        }
        return true;
    }

	@Override
	public String toString() {
		return "Usuario [idUsuario=" + idUsuario + ", identificador=" + identificador + ", senha=" + senha + ", perfil="
				+ perfil + "]";
	}

   
}


const livros = [
  {
    id: '1',
    name: 'Tratado de Fisiologia Médica',
    img: './img/medicina1.jpg', 
    alt:'Tratado de fisiologia médica',
    writer: 'Guyton & Hall',
    price: 650,
    category: 'medicina',
    description:'Conhecido e respeitado por seu estilo de apresentação único e pelo foco no conteúdo mais relevante para estudantes da área da Saúde e médicos e profissionais que desejem revisar os princípios básicos necessários para a compreensão da fisiopatologia das doenças humanas, Guyton & Hall | Tratado de Fisiologia Médica chega à sua 14a edição, atualizado e revisado, com a inclusão de novos princípios de fisiologia. Seu texto didático, aliado aos recursos pedagógicos e ao projeto gráfico ímpar, que garantem o máximo de aprendizado e retenção de conceitos complexos, torna este best-seller o favorito dos estudantes em todo o mundo.Principais características:Perspectiva clinicamente orientada, unindo fisiologia básica com fisiopatologiaÊnfase nos princípios importantes que nortearão a tomada de decisão clínicaMais de 1.200 ilustrações e diagramas em cores – todos cuidadosamente elaborados para facilitar a compreensão da fisiologiaCobertura clínica expandida, incluindo obesidade, distúrbios metabólicos e cardiovasculares, doença de Alzheimer e outras doenças degenerativasMaterial suplementar online: vídeos de processos fisiológicos e sons cardíacos.',
    newRealease: 'false',
  },
  {
    id: '2',
    name: 'Fisiologia Humana',
    img: './img/medicina2.jpg', 
    alt:'Fisiologia humana',
    writer: 'Dee Unglaub Silverthorn',
    price: 280,
    category: 'medicina',
    description:'A 7ª edição de Fisiologia humana preserva sua característica principal ao oferecer uma abordagem integrada aos sistemas do corpo humano. Nesta edição, as áreas de neurobiologia, sistema digestório e fisiologia reprodutiva foram amplamente atualizadas para refletir descobertas recentes. Objetivos de aprendizagem expandidos, novos resumos anatômicos e figuras essenciais, além de imagens tridimensionais e novas questões para revisão ao longo dos capítulos são alguns dos recursos didáticos importantes que fazem deste livro um sucesso entre estudantes e professores.',
    newRealease: 'false'
  },
   {
    id: '3',
    name: 'Pessoa, Direitos e Direitos',
    img: './img/direito1.jpg', 
    alt:'Pessoa, Direitos e Direitos',
    writer: 'Diogo Leite De Campos',
    price: 90,
    category: 'adevas',
    description:'Trata-se da pessoa em si mesma e em relação com os outros. Acentua-se a dignidade da pessoa e os direitos que esta gera. Estabelece-se a coincidência entre ser humano, pessoa e personalidade jurídica. Inicio e termo da personalidade. Defende-se um Direito inclusivo do outro, procurando a justiça da relação. Afasta-se qualquer direito da pessoa sobre outra pessoa A pessoa é sempre central e agregadora na sociedade e na relação.',
    newRealease: 'false'
  },
   {
    id: '10',
    name: 'Manual de Direito Civil',
    img: './img/direito2.jpg', 
    alt:'Manual de Direito Civil',
    writer: 'Flávio Tartuce',
    price: 250,
    category: 'adevas',
    description:'O livro também apresenta a interação teórica e prática a respeito da crise decorrente da pandemia da Covid-19 e seus impactos para todo o Direito Privado, bem como interações entre as categorias da civilística contemporânea e sua efetividade. Com destaque especial para os julgados constantes dos Informativos de Jurisprudência e da ferramenta Jurisprudência em Teses, ambos do Superior Tribunal de Justiça, o livro expõe as grandes teses do Direito Civil Contemporâneo, tais como: a teoria do diálogo das fontes, o Direito Civil Constitucional, os princípios do Código Civil de 2002, a eficácia horizontal dos direitos fundamentais, a técnica de ponderação, as eficácias internas e externas da função social do contrato, os conceitos parcelares da boa-fé objetiva (supressio, surrectio, tu quoque, exceptio doli, venire contra factum proprium, duty to mitigate the loss e Nachfrist), a visão contemporânea da responsabilidade civil e do inadimplemento obrigacional, a função social da posse, a função social e socioambiental da propriedade, as novas entidades familiares, a parentalidade socioafetiva, a multiparentalidade, as principais controvérsias da sucessão legítima, entre outras.?',
    newRealease: 'false'
  },
   {
    id: '5',
    name: 'Tecnologia da informação',
    img: './img/ti1.jpg', 
    alt:'Tecnologia da informação',
    writer: 'Fernando José Barbin Laurindo',
    price: 170,
    category: 'tecnologia',
    description:'Este livro apresenta uma visão geral sobre a estratégia de TI e dos modelos de análise e de avaliação da TI, em especial aqueles voltados para avaliar sua eficácia. O texto expõe e discute modelos que vinculam a estratégia de TI à de negócio, avaliando sua eficácia e indicando diretrizes para a análise e avaliação da TI como ferramenta estratégica, sobretudo em ambientes turbulentos e na Nova Economia. Com base nos pontos mais importantes observados, é proposto um modelo para analisar e avaliar a eficácia da TI nas organizações. A inclusão de vários estudos de caso facilita e ilustra a aplicação desse modelo e mostra os resultados que podem ser obtidos. A visão abrangente sobre o tema estratégia de TI é justificada pela forma como os temas foram desenvolvidos ao longo de seus nove capítulos, complementados ainda por dois apêndices: Roteiro para desenvolver o MAN/TI e o MAVE/TI e o Método da Análise Hierárquica (AHP). Livro destinado a diretores, gerentes e profissionais da área de Tecnologia de Informação e engenheiros de produção, administradores, analistas de negócios e de sistemas. Livro-texto para a disciplina Gestão de Tecnologia da Informação e leitura complementar para a disciplina Gestão Estratégica da Produção dos cursos de graduação em Engenharia de Produção, Administração e Computação.',
    newRealease: 'false'
  },
   {
    id: '6',
    name: 'O inglês na TI',
    img: './img/ti2.jpg', 
    alt:'O inglês na TI',
    writer: 'Cristina Schumacher',
    price: 60,
    category: 'tecnologia',
    description:'O inglês na área da Tecnologia da Informação, enfocado a partir dos estágios de um projeto planejamento especificações, testes e suporte técnico dentre outros. O livro contém um guia de conversação, frases úteis, glossário inglês-português e português inglês, dicas culturais e lingísticas e diálogos exemplificando interações típicas.',
    newRealease: 'false'
  },
   {
    id: '7',
    name: 'Neurociências',
    img: './img/medicina3.jpg', 
    alt:'Neurociências',
    writer: 'Mark F. Bear',
    price: 220,
    category: 'medicina',
    description:'Aclamado por seu estilo claro e acessível, com ilustrações impecáveis e uma equipe de autores que é referência na área, esta 4ª edição de Neurociências: desvendando o sistema nervoso diferencia-se pela abordagem didática e inovadora no estudo das neurociências, enfatizando as bases biológicas do comportamento. Nos últimos anos, o campo das neurociências foi transformado pelo emprego de novas tecnologias e a explosão de conhecimentos que acumulamos sobre o encéfalo. O genoma humano foi sequenciado, novos e sofisticados métodos de engenharia genética foram desenvolvidos, e hoje temos uma visão muito mais elaborada do sistema nervoso em nível molecular. Também compreendemos melhor a base genética de diversas doenças neurológicas e psiquiátricas e surgiram novos métodos que permitem visualizar e estimular tipos específicos de células nervosas e suas conexões no encéfalo. Esta edição foi atualizada para refletir esses e outros novos desenvolvimentos instigantes, tornando-os acessíveis a todos os interessados neste campo',
    newRealease: 'true'
     
  },
   {
    id: '8',
    name: 'Curso de Direitos Humanos',
    img: './img/direito3.jpg', 
    alt:'Curso de Direitos Humanos',
    writer: 'Andre de Carvalho',
    price: 110,
    category: 'adevas',
    description:'O Curso de Direitos Humanos; de André de Carvalho Ramos; tem o propósito de expor; de modo adequado à importância e complexidade da matéria; os principais delineamentos normativos e precedentes judiciais da disciplina; para que os leitores possam; depois; aprofundar em um tema específico. Detalha os principais institutos da matéria; abarcando a visão nacional e internacional; dos direitos humanos e seus órgãos de proteção; bem como o estudo dos direitos em espécie; acompanhado da análise dos contornos dos casos concretos apreciados pelos tribunais do País. Entre as novidades da 9ª edição; estão: novos temas; como direito ao meio ambiente; corrupção e direitos humanos; direito à proteção de dados pessoais e atualização do impacto sobre os direitos humanos da pandemia da COVID-19; foram acrescidos dez novos casos comentados da Corte Interamericana de Direitos Humanos; bem como quatro casos em trâmite contra o Brasil e três opiniões consultivas da Corte IDH; e está de acordo com a Lei Maria Ferrer ¿ Lei n. 14.245; de 22 de novembro de 2021; que protege vítimas de crimes sexuais em julgamentos.',
    newRealease: 'true'
  },
   {
    id: '9',
    name: 'Governança de TI',
    img: './img/ti3.jpg', 
    alt:'Governança de TI',
    writer: 'Peter Weill',
    price: 70,
    category: 'tecnologia',
    description:'Como administrar os direitos decisórios de TI na busca por resultados superiores Como as empresas com melhor desempenho administram os direitos decisórios de TI na busca por resultados superiores Um grande número de iniciativas de TI tem fracassado em proporcionar os resultados essenciais que as empresas esperavam. Neste importante livro, os especialistas Peter Weill e Jeanne W. Ross explicam por quê – e mostram exatamente o que as empresas devem fazer para colher os reais frutos de seus investimentos em TI. Com base num estudo feito junto a 250 empresas de todo o mundo, Weill e Ross afirmam que o valor de negócios de TI resulta diretamente de uma governança de TI eficaz – da alocação, pela empresa, da responsabilidade e dos direitos decisórios. Suas pesquisas revelam que empresas com governança de TI superior tem lucros no mínimo 20% maiores do que as com má governança, considerados os mesmos objetivos estratégicos. Mas somente 38% da alta gerência conseguem descrever com precisão sua governaça de TI – como, então, os demais gerentes poderão tomar boas decisões pela empresa a esse respeito? Em Governança de TI, os autores mostram como conceber e implementar um sistema de direitos decisórios que endereçem tres questões fundamentais: Quais decisões devem ser tomadas para garantir um uso e uma gestão apropriados da TI? ',
    newRealease: 'true'
  }, 
]




if (document.querySelector('[list-all]') != null){
  const obj = document.querySelector('[list-all]')   
  const list= (livros) => {
  return livros.map((item) => {    
    return (
      `          
      <div class="item">
          <img class="imglivro" src=${ item.img } alt=${ item.alt } />
          <p class="nomelivro">${ item.name }</p>
          <p class="dsclivro">${ item.writer }</p>
          <p class="nomelivro">R$ ${ item.price },00</p>
          <a href="./carrinho.html?id=${ item.id }"><input type="button" class="button" value="Comprar" /></a>             
          <button onclick="openModal('dv-modal${ item.id }')" id="myBtn">Descrição</button>
          <div id="dv-modal${ item.id }" class="modal">
            <div class="modal-content">
                <div class="modal-header">
                    <h1>Descrição</h1>
                </div>
                <div class="modal-body">
                   <span>${ item.description }</span>
                </div>
                <div class="modal-footer">
                    <input type="button" value="Fechar" id="myBtn" onclick="closeModal('dv-modal${ item.id }')">
                </div>
              </div>
          </div>
      </div>
      `
    )
  }).join('')
  }    
  obj.innerHTML = list(livros) 
} 



if (document.querySelector('[list-home]') != null){
  const obj= document.querySelector('[list-home]')   
  const list = (livros) => {
  return livros
    .filter(p => p.newRealease === 'false')
    .map((item) => {
    return (
      `          
      <div class="item">
          <img class="imglivro" src=${ item.img } alt=${ item.alt } />
          <p class="nomelivro">${ item.name }</p>
          <p class="dsclivro">${ item.writer }</p>
          <p class="nomelivro">R$ ${ item.price },00</p>
          <a href="./carrinho.html?id=${ item.id }"><input type="button" class="button" value="Comprar" /></a>        
          <button onclick="openModal('dv-modal${ item.id }')" id="myBtn">Descrição</button>
          <div id="dv-modal${ item.id }" class="modal">
            <div class="modal-content">
                <div class="modal-header">
                    <h1>Descrição</h1>
                </div>
                <div class="modal-body">
                   <span>${ item.description }</span>
                </div>
                <div class="modal-footer">
                    <input type="button" value="Fechar" id="myBtn" onclick="closeModal('dv-modal${ item.id }')">
                </div>
              </div>
          </div>
      </div>
      `
    )
  }).join('')
  }    
  obj.innerHTML = list(livros) 
} 

if (document.querySelector('[newRealesa]') != null){
  const obj = document.querySelector('[newRealesa]')
  const list = (livros) => {
  return livros
    .filter(p => p.newRealease === 'true')    
    .map((item) => {
    return (
      `          
      <div class="item">
          <img class="imglivro" src=${ item.img } alt=${ item.alt } />
          <p class="nomelivro">${ item.name }</p>
          <p class="dsclivro">${ item.writer }</p>
          <p class="nomelivro">R$ ${ item.price },00</p>
         <a href="./carrinho.html?id=${ item.id }"><input type="button" class="button" value="Comprar" /></a>            
          <button onclick="openModal('dv-modal${ item.id }')" id="myBtn">Descrição</button>
          <div id="dv-modal${ item.id }" class="modal">
            <div class="modal-content">
                <div class="modal-header">
                    <h1>Descrição</h1>
                </div>
                <div class="modal-body">
                   <span>${ item.description }</span>
                </div>
                <div class="modal-footer">
                    <input type="button" value="Fechar" id="myBtn" onclick="closeModal('dv-modal${ item.id }')">
                </div>
              </div>
          </div>
      </div>
      `
    )
  }).join('')
  }    
  obj.innerHTML = list(livros) 
} 

if (document.querySelector('[medicina]') != null){   
  const obj = document.querySelector('[medicina]')
  const list = (livros) => {
  return livros
    .filter(p => p.category === 'medicina')    
    .map((item) => {
    return (
      `          
      <div class="item">
          <img class="imglivro" src=${ item.img } alt=${ item.alt } />
          <p class="nomelivro">${ item.name }</p>
          <p class="dsclivro">${ item.writer }</p>
          <p class="nomelivro">R$ ${ item.price },00</p>
          <a href="./carrinho.html?id=${ item.id }"><input type="button" class="button" value="Comprar" /></a>           
          <button onclick="openModal('dv-modal${ item.id }')" id="myBtn">Descrição</button>
          <div id="dv-modal${ item.id }" class="modal">
            <div class="modal-content">
                <div class="modal-header">
                    <h1>Descrição</h1>
                </div>
                <div class="modal-body">
                   <span>${ item.description }</span>
                </div>
                <div class="modal-footer">
                    <input type="button" value="Fechar" id="myBtn" onclick="closeModal('dv-modal${ item.id }')">
                </div>
              </div>
          </div>
      </div>
      `
    )
  }).join('')
  }    
    obj.innerHTML = list(livros) 
}

if (document.querySelector('[adevas]') != null){   
  const obj = document.querySelector('[adevas]')
  const list = (livros) => {
  return livros
    .filter(p => p.category === 'adevas')    
    .map((item) => {
    return (
      `          
      <div class="item">
          <img class="imglivro" src=${ item.img } alt=${ item.alt } />
          <p class="nomelivro">${ item.name }</p>
          <p class="dsclivro">${ item.writer }</p>
          <p class="nomelivro">R$ ${ item.price },00</p>
         <a href="./carrinho.html?id=${ item.id }"><input type="button" class="button" value="Comprar" /></a>             
          <button onclick="openModal('dv-modal${ item.id }')" id="myBtn">Descrição</button>
          <div id="dv-modal${ item.id }" class="modal">
            <div class="modal-content">
                <div class="modal-header">
                    <h1>Descrição</h1>
                </div>
                <div class="modal-body">
                   <span>${ item.description }</span>
                </div>
                <div class="modal-footer">
                    <input type="button" value="Fechar" id="myBtn" onclick="closeModal('dv-modal${ item.id }')">
                </div>
              </div>
          </div>
      </div>
      `
    )
  }).join('')
  }    
    obj.innerHTML = list(livros) 
}

if (document.querySelector('[tecnologia]') != null){   
  const obj = document.querySelector('[tecnologia]')
  const list = (livros) => {
  return livros
    .filter(p => p.category === 'tecnologia')    
    .map((item) => {
    return (
      `          
      <div class="item">
          <img class="imglivro" src=${ item.img } alt=${ item.alt } />
          <p class="nomelivro">${ item.name }</p>
          <p class="dsclivro">${ item.writer }</p>
          <p class="nomelivro">R$ ${ item.price },00</p>
         <a href="./carrinho.html?id=${ item.id }"><input type="button" class="button" value="Comprar" /></a>             
          <button onclick="openModal('dv-modal${ item.id }')" id="myBtn">Descrição</button>
          <div id="dv-modal${ item.id }" class="modal">
            <div class="modal-content">
                <div class="modal-header">
                    <h1>Descrição</h1>
                </div>
                <div class="modal-body">
                   <span>${ item.description }</span>
                </div>
                <div class="modal-footer">
                    <input type="button" value="Fechar" id="myBtn" onclick="closeModal('dv-modal${ item.id }')">
                </div>
              </div>
          </div>
      </div>
      `
    )
  }).join('')
  }    
    obj.innerHTML = list(livros) 
}

if (document.querySelector('[carrinho]') != null){   
  const obj = document.querySelector('[carrinho]')
   const montarCarrinho = (livros) => {
    var url = window.location.href;   	
    var res = url.split('?'); 
    var param = res[1].split('=');
    var id = param[1];
    return livros
    .filter(p => p.id === id)    
    .map((item) => {
    return (
      `        
     
        <img src=${ item.img } alt=${ item.alt } />
        <div class="container-carrinho-descricao">
          <div>
            <p>
              ${ item.name }
            </p>
             <p>
              ${ item.writer }
            </p>
            <p>Preço: R$ ${ item.price },00</p>
          </div>
          <div>
            <p>Quantidade:</p>
            <input
              type="number"
              min="0"
              value="1"
              id="quantidade"
              onchange = "totaliza(${ item.price })"
            />
            <p>Total: R$</p>
            <input type="number" id="valor" value="${ item.price.toFixed(2) }"  readonly />
          </div>
          <button onclick="openModal('dv-modal')" class="myBtn">Comprar</button>
        </div>
      `
    )
  }).join('')
  } 
  obj.innerHTML = montarCarrinho(livros)
}



  













                                     
  


                                     

                                     


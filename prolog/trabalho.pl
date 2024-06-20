:- data_source(dbpedia_enxadristas,
    sparql('
        PREFIX dbo: <http://dbpedia.org/ontology/>
		PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>

        SELECT DISTINCT ?name ?rating ?title ?country ?birthdate
        WHERE {
            ?subject a dbo:ChessPlayer ;
                rdfs:label ?name ;
                dbo:rating ?rating ;
                dbo:title ?title ;
                dbo:birthDate ?birthdate ;
                dbo:country ?countryResource .

            ?countryResource rdfs:label ?country .
            FILTER(lang(?name) = "en") 
            FILTER(lang(?country) = "en") 
            FILTER(?rating < 3000)
        }
          ORDER BY DESC(?rating)
          LIMIT 10'
		,
           [ endpoint('https://dbpedia.org/sparql')])).

enxadristas(Nome, Rating, Titulo, Nascimento, Pais) :- dbpedia_enxadristas{name: Nome, rating: Rating, title: Titulo, birthdate: Nascimento, country: Pais}.

rating_alto(Jogador) :- 
    enxadristas(Jogador, Rating, _, _,_),
    Rating > 2000.

titulo_grande_mestre(Jogador) :-
    enxadristas(Jogador, _, "Grandmaster", _, _).

pais_jogador(Jogador, Pais) :-
    enxadristas(Jogador, _, _, _, Pais).

classificacao_maxima(Classificacao) :-
    findall(Rating, enxadristas(_, Rating, _, _, _), Ratings),
    max_list(Ratings, Classificacao).

classificacao_maxima_pais(Pais, ClassificacaoMaxima, NomeJogador) :-
    findall(Rating-Nome, (enxadristas(Nome, Rating, _, _, Pais), Rating \= ''), Pares),
    max_list(Pares, ClassificacaoMaxima-NomeJogador).

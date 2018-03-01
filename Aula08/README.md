Busca binária

Busca binária é um algoritmo que divisão e conquista usado em sua maior parte para minimizar o tempo de uma busca linear.

Imagine você com um livro de 1000 páginas em mãos no momento em que o professor pede para que abra na página 500. Existem várias maneiras de se alcançar a página 500 e duas delas são, ir de uma em uma até que se alcance a página e uma outra maneira é pular direto para a metade do livro.

Perceba que no exemplo acima uma busca linear (passar de página em página) demoraria muito mais do que ir diretamente para a metade do livro. E fazendo da segunda maneira invulantariamente você acaba aplicando o que chamamos de busca binária.

O algortimo

Usando a mesma ideia do livro porém agora em uma linguagem mais computacional, no lugar de 1000 páginas temos um vetor de 1000 posições onde na i-ésima posição temos o valor i, ou seja v[i] = i. Mas agora com uma pequena alteração, não iremos procurar o valor 500 e sim o valor 375. Novamente aplicando a mesma ideia que usamos no exemplo. 
Primeiro vamos para a posição 500 (metade entre 0 e 1000) e vamos perguntar se o valor que buscamos (375) é menor, igual ou maior que 500, e como 375 é menor que 500 podemos descartar todos os números maiores que 500, agora temos um espaço menor de elementos (0 a 500) e novamente vamos diminuir pela metade e perguntar se o valor da metade é menor, igual ou maior que o elemento que buscamos, e temos que 250 é menor que 375 e dessa vez vamos descartar todos os elementos menores que 250 e diminuir ainda mais o nosso alcance, agora estamos entre 250 e 500 e pela ultima vez dividiremos pela metade e então encontraremos o número 375.

Perceba que o algortimo é bastante simples porém precisamos de uma condição muito importante para que ele funcione! No momento em que é dividido pela metade nós fazemos uma pergunta para saber que parte podemos descartar, e para que seja possível responder a essa pergunta precisamos garantir que nossa função seja crescente ou decrescente. Imagine esse exemplo simples, temos o seguinte vetor [3, 1, 5, 4, 2] e buscamos o valor 2. Na primeira vez que dividirmos e perguntarmos se o valor 5 e menor, igual ou maior que 2 teremos a resposta que 5 é maior que 2 e com isso iriamos descartar todos os elementos a direita de 5 e junto com esses elementos o 2 iria embora e nunca iriamos achar resposta.

Formalmente falando, seja um função F ordenada para verificarmos se um dado valor X pertence a F basta selecionar o elemento no centro do segmento e verificar se seu valor é menor, igual ou maior que X e com isso diminuir o segmento de maneira condizente com a resposta, faremos isso até que se ache X ou que não tenha mais segmento para ser dividido.

Complexidade

Suponha um vetor ordenado de tamanho N onde vamos aplicar o algortimo de busca binária onde o valor procurado não está presente no vetor (pior caso), na nossa primeira iteração iremos dividir o vetor em 2 partes ou seja teremos N/2 elementos restantes, na segunda iteração iremos dividir do que restou e teremos (N/2)/2 ou seja N/4, seguindo essa logica na K-ésima iteração teremos divido por 2 K vezes ou seja N/(2^K) e como estamos calculando complexidade temos que pensar no pior caso ou seja quando chegarmos no ponto onde teremos um espaço de apenas 1 elemento. O que estamos buscando é K (quantidade de passos) para o pior caso então temos que N/(2^K) = 1 daí temos que N = 2^K tirando o log2 dos dois lados temos que K = log2(N). Então no pior caso nosso algortimo demora log2(N), N sendo o tamanho do vetor inicial.

Ressalvas

Existem muitas aplicações interessantes relacionadas a busca binária. Nesse documento ressaltamos apenas a aplicação mais simples para que se torne simples e didático esse primeiro contato com o algortimo.

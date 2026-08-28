import { StyleSheet, Text, View, TextInput, Button } from 'react-native';
import React, { useState } from 'react';


export default function App() {
  
  const [veiculos, setVeiculos] = useState ([
    {id: 1, modelo: 'Montana RS', revisado: false},
    {id: 2, modelo: 'Bros 160', revisado: false}
    ]);
  
  const [textoBusca, setTextoBusca] = useState('');

  const veiculosFiltrados = veiculos.filter(({modelo}) => 
    modelo.toLowerCase().includes(textoBusca.toLowerCase()) 
    );

  const finalizarRevisao = (idDoVeiculo) => {
    const listaAtualizada = veiculos.map(({id, modelo, revisado}) => {
      if (id === idDoVeiculo) {
        return {id, modelo, revisado: true};
      }
      return {id, modelo, revisado};
    });
    
    setVeiculos(listaAtualizada);
  };

  return (
    <View style={styles.container}>
      
      <Text style={styles.paragraph}>
      Digite o modelo do veículo:
      </Text>

      <TextInput
      style={{borderWidth: 1, padding: 10, margin: 5, marginBottom: 30 }}
      value={textoBusca}
      onChangeText={setTextoBusca}
      />

      <Text style={styles.tituloLista}>
        Lista de Veículos:
      </Text>
 { /* Modelo sem desestruturacao

    {veiculos.map((veiculo) => (
        <Text key={veiculo.id}>
          Modelo: {veiculo.modelo}
        </Text>
      ))}  */} 

{/* Modelo com desestruturacao 
      
      {veiculos.map(({id, modelo}) => (
        <Text key={id}>
        ID do veículo: {id} - Modelo do veículo: {modelo}   
        </Text>
      ))}  */}

{/* Modelo com desestruturacao e filter */}

      {veiculosFiltrados.length > 0 ? (
        veiculosFiltrados.map(({ id, modelo, revisado }) => (
          <View key={id} style={{marginBottom: 20}}>
          <Text key={id} style={styles.itemVeiculo}>
            ID do veículo: {id} - Modelo do veículo: {modelo} - Revisado: {revisado ? 'Sim' : 'Não'}   
          </Text>
            <Button
              title="Revisão"
              onPress={() => (finalizarRevisao(id))}
            />
          </View>
        ))
      ) : (
        <Text style={styles.itemVeiculo}>Nenhum veículo encontrado.</Text>
      )}

    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#ecf0f1',
    padding: 8,
    paddingTop: 110,
  },

  paragraph: {
    margin: 5,
    fontSize: 18,
    textAlign: 'left',
  },

  tituloLista: {
    fontSize: 20,
    fontWeight: 'bold',
    textAlign: 'center',
    marginTop: 15,
    marginBottom: 20,
    color: '#333',
  },

  itemVeiculo: {
    fontSize: 16,
    marginVertical: 8, 
    paddingHorizontal: 5,
  },
}); 

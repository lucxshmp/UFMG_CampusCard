O Sistema Universitário Unificado: UFMG CampusCard é um aplicativo idealizado pelos autores durante o curso da disciplina de Programação e Desenvolvimento de Software II. Surgiu da ideia de facilitar o dia a dia de quem frequenta a Universidade Federal de Minas Gerais - UFMG, podendo ser utilizado por qualquer aluno interessado.

\[
\begin{align*}
\text{Classe} & \quad \text{Superclasses} & \quad \text{Subclasses} & \quad \text{Tipo} & \quad \text{Responsabilidades} & \quad \text{Colaboradores} \\
\hline
\text{Restaurante} & \quad & \quad & \quad 1 & \text{pagamento(); deposito(); consultar_saldo(); gerar_GRU(); lerQRCODE();} & \text{Usuario, Saldo} \\
\text{Usuário} & \quad & \quad \text{Informações_Pessoais, Login} & \quad 2 & \text{novo_usuario(); deletar_conta(); editar_conta(); nome(); senha(); e-mail(); cpf(); matricula(); nivel_FUMP(); predios_acesso(); endereço();} & \text{Restaurante, Saldo, Grade, Calendario, Transporte, Carteira Estudante, Rotina} \\
\text{Carteira_Estudante} & \quad & \quad & \quad 1 & \text{libera_catraca(); gerar_carteira_digital(); consultar_acesso(); invalidar_carteira();} & \text{Usuario} \\
\text{Transporte} & \quad & \quad \text{Interno, Moradia, Externo, Van} & \quad 2 & \text{proximo_onibus_interno(data_e_hora, linha); proximo_onibus_moradia(data_e_hora, linha); todos_os_onibus(); linhas_externas(); van(regiao, turno);} & \text{Dados_transporte, Usuario} \\
\text{Dados_transporte} & \quad & \quad & \quad 2 & \text{inserir_linha(numero_linha); inserir_horarios()} & \text{Transporte} \\
\text{Calendario} & \quad & \quad & \quad 1 & \text{criar_calendário(); status_entrega(); notificar_entrega(); gerenciar_entrega(nome_da_demanda, disciplina, data_de_entrega);} & \text{Rotina, Usuario, Grade Semanal} \\
\text{Grade Semanal} & \quad & \quad & \quad 1 & \text{montar_grade(disciplina, hora, dia_da_semana, sala, predio); editar_grade();} & \text{Calendario} \\
\text{Rotina} & \quad & \quad & \quad 2 & \text{disciplina(codigo, nome); data(); hora(); sala(); predio();} & \text{Usuário, Calendário, Grade Semanal} \\
\text{Saldo} & \quad & \quad & \quad 2 & \text{diminuir_saldo(fump); adicionar_saldo(valor);} & \text{Restaurante, Usuário} \\
\end{align*}
\]

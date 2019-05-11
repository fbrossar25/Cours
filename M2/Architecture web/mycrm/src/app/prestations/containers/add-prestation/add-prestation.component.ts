import { PrestationsService } from './../../services/prestations.service';
import { Prestation } from './../../../shared/model/prestation';
import { Component, OnInit, createPlatformFactory } from '@angular/core';
import { FormBuilder, FormControl, FormGroup, Validators } from '@angular/forms';
import { StatePrestation } from 'src/app/shared/enums/state-prestation.enum';
import { TypePrestation } from 'src/app/shared/enums/type-prestation.enum';

const prestationInit = new Prestation();

@Component({
  selector: 'app-add-prestation',
  templateUrl: './add-prestation.component.html',
  styleUrls: ['./add-prestation.component.scss']
})
export class AddPrestationComponent implements OnInit {

  prestation: Prestation;
  form: FormGroup;
  states = Object.values(StatePrestation);
  types = Object.values(TypePrestation);
  constructor(private fb: FormBuilder, private prestationsService: PrestationsService) { }

  ngOnInit() {
    this.createForm();
  }

  private createForm(): void {
    this.form = this.fb.group({
      id: [prestationInit.id, Validators.required],
      intitule : [prestationInit.intitule, Validators.required],
      date_debut: prestationInit.date_debut,
      date_fin: prestationInit.date_fin,
      tjm_ht : [prestationInit.tjm_ht, Validators.required],
      nb_jours : [
        prestationInit.nb_jours,
        Validators.compose([Validators.min(1), Validators.required])
      ],
      taux_tva : prestationInit.taux_tva,
      state : prestationInit.state,
      type: prestationInit.type
    });
  }

  private register() {
    if (this.form.valid) {
      this.prestationsService.add(this.prestation);
    }
  }

}
